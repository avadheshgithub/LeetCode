class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int prev2 = 1;
        int prev1 = 1;  
        
        for (int i=1;i<s.size();i++) {
            int curr = 0;
            
            if (s[i]>='1' && s[i]<='9') // single digit
                curr += prev1;
            
            int two = (s[i-1]-'0')*10 + (s[i]-'0'); // two digits
            if (two>=10 && two<=26) 
                curr += prev2;
            
            if (curr == 0) return 0; //IMP
            
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};