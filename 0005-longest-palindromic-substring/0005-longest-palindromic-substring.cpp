class Solution {
public:
    int palindrome(string s,int L, int R){
        while(L>=0 && R<s.length() && s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }

    string longestPalindrome(string s) {
        if(s.size()==0) return "";

        int L=0, R=0;
        for(int i=0;i<s.length();i++){
            int len1 = palindrome(s,i,i);
            int len2 = palindrome(s,i,i+1);

            int len = max(len1,len2);
            if(len > R-L){
                L = i - (len-1)/2;
                R = i + (len/2);
            }
        }
        return s.substr(L,R-L+1);
        
    }
};