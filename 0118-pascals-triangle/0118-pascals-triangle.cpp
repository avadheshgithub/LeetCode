class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>dp(n);

        for(int i=0;i<n;i++){
            dp[i].resize(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 or j==i) dp[i][j]=1;
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        return dp;
    }
};