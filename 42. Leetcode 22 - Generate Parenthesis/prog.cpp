// genrate Parenthesis
// Lettcode 22

class Solution {
public:
    void generate(vector<string>& ans,string s, int open,int close,int n){
        if(close==n){
            ans.push_back(s);
            return;
        }
        if(open<n)generate(ans, s+'(',open+1,close,n); // left -> open
        if(close<open) generate(ans, s+')',open,close+1,n); // right - close
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans,"",0,0,n);
        return ans;
    }
};
