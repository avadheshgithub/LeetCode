// Problem - kth Symbol in Grammar
// Leetcode - 779


//Time Complexity - O(n)
// SPace Complexity - O(1)

// Methode 01 - recursive
class Solution {
public:
    int kthGrammar(int n, int k) {
        // Tree Structure --> Replace 0=>01 && 1=>10
        if(n==1) return 0;
        if(k%2==0){
            int a = kthGrammar(n-1,k/2); // divide by 2 && flip
            if(a==0) return 1;
            else return 0;
        }
        else return kthGrammar(n-1,k/2 +1); // same and dont Flip
    }
};


// TIme Complexity - O(n);
// space Complexity - O(1);

// Methode 02 - iterative
class Solution {
public:
    int kthGrammar(int n, int k) {
        // Tree Structure --> Replace 0=>01 && 1=>10
        int ans = 0;
        while(n>1){
            if(k%2==0){
                if(ans==0) ans = 1; // flip
                else ans = 0;
            }
            k = (k+1)/2; // divide by 2
            n--;
        }
        return ans;
    }
};


// Time COmplexity = 
// SPace Complexity - 
// Methode 03 - bit Manipulation
class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans = 0;
        k--; 
        while(k>0){
            ans ^= (k&1); // flip
            k >>= 1; // divide by 2
        }
        return ans;
    }
};