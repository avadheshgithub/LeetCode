class Solution {
public:
    bool isMatch(string s, string p) {
        if(s=="" or p=="") return true;

        vector<vector<bool>>dp(s.length()+1,vector<bool>(p.length()+1));
        dp[0][0] = true; // base

        for(int i=0;i<p.length();i++){
            if(p[i]=='*' && dp[0][i-1]) dp[0][i+1] = true;
        }

        for(int i=0;i<s.length();i++){
            for(int j=0;j<p.length();j++){

                if(p[j]=='.') dp[i+1][j+1]= dp[i][j]; // see diagonal

                if(p[j]==s[i]) dp[i+1][j+1] = dp[i][j]; // see diagonal

                if(p[j]=='*'){
                    if(p[j-1]!=s[i] && p[j-1]!='.')   dp[i+1][j+1] = dp[i+1][j-1]; // just before box
                    
                    else{
                        dp[i+1][j+1] = (dp[i+1][j] or dp[i][j+1] or dp[i+1][j-1]); // any true
                    }
                }

            }
        }
        return dp[s.length()][p.length()];


    }
};