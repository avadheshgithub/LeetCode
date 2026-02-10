class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;
        int n = temp.size();

        vector<int> lps(n, 0); // KMP Algo

        for(int i = 1; i < n; i++){
            int j = lps[i-1];

            while(j>0 && temp[i]!=temp[j])  j=lps[j-1];
            if(temp[i]==temp[j]) j++;
            lps[i] = j;
        }

        int palLen = lps[n-1];   // longest palindromic prefix
        string suffix = s.substr(palLen);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};
