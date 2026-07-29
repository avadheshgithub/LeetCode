#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    
    long long cappedComb(int n, int r, long long MAX) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r; // Optimize: nCr = nC(n-r)
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            unsigned long long temp = (unsigned long long)res * (n - i + 1);
            res = temp / i;
            if (res >= MAX) return MAX;
        }
        return res;
    }

    
    long long totalPerms(const vector<int>& counts, long long MAX) {
        long long ways = 1;
        int current_length = 0;
        
        for (int c : counts) {
            if (c == 0) continue;
            current_length += c;
            long long comb = cappedComb(current_length, c, MAX);
            
            if (comb >= MAX) return MAX;
            if (MAX / ways < comb) return MAX; // overflow check
            ways *= comb;
        }
        
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string mid = "";
        vector<int> counts(26, 0);
        int N = 0; // Length of the half string
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid += (char)(i + 'a');
            }
            counts[i] = freq[i] / 2;
            N += counts[i];
        }

        long long MAX = k + 1; // We only care about counts 
        if (totalPerms(counts, MAX) < k) {
            return "";
        }

        string half = "";
        
        for (int i = 0; i < N; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (counts[c] == 0) continue;
                
                counts[c]--; 
                long long P = totalPerms(counts, MAX);
                
                if (P >= k) {
                  
                    half += (char)(c + 'a');
                    break;
                } else {
                  
                    k -= P;
                    counts[c]++;
                }
            }
        }

        string res = half + mid;
        reverse(half.begin(), half.end());
        res += half;
        
        return res;
    }
};