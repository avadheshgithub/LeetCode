class Solution {
public:
    int checkPalindrome(string s,int L, int R){
        int count=0;
        while(L>=0 && R<s.length() && s[L]==s[R]){
            count++;
            L--;
            R++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans += checkPalindrome(s,i,i);  // odd
            ans += checkPalindrome(s,i,i+1); //even
        }
        return ans;
    }
};