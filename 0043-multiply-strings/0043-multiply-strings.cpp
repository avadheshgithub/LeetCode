class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0"||num2=="0") return "0";

        vector<int> result(num1.size() + num2.size(), 0);
    
        for (int i=num1.size()-1; i>=0;i--){
            for (int j=num2.size()-1;j>= 0;j--) {
                int mul = (num1[i]-'0') * (num2[j]-'0');

                int total = mul + result[i+j+1];
                
                result[i+j+1] = total % 10;
                result[i+j] += total / 10;  //carry
            }
        }
        
        string ans;
        bool leadingZero = true;
        
        for (int digit : result) {
            if (digit == 0 && leadingZero) continue;
            leadingZero = false;
            ans += '0' + digit;
        }
        return ans.empty() ? "0" : ans;
    }
};