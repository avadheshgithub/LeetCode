class Solution {
public:
    bool isPalindrome(int n) {
        string str = to_string(n);
        int len = str.length();

        for(int i=0;i<len/2;i++){
            if(str[i]!=str[len-i-1]) return false;
        }
        
        return true;
    }
};