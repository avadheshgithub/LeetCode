class Solution {
public:
    void paren(int open,int close,int n,string s,vector<string> &ans){
        if(close==n){
            ans.push_back(s);
            return;
        }
        if (open<n)    paren(open+1,close,n,s+'(',ans);
        if(close<open) paren(open,close+1,n,s+')',ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        paren(0,0,n,"",ans);
        return ans;
    }
};
