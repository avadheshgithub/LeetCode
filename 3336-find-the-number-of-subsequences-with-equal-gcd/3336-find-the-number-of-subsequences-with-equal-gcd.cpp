class Solution {
public:
    const int MOD = 1e9+7;

    int n;
    vector<int> nums;
    int dp[205][201][201];

    int solve(int idx,int g1,int g2){

        if(idx==n)
            return (g1>0 && g1==g2);

        int &res=dp[idx][g1][g2];

        if(res!=-1)
            return res;

        res=solve(idx+1,g1,g2);

        int ng1=(g1==0)?nums[idx]:gcd(g1,nums[idx]);
        res=(res+solve(idx+1,ng1,g2))%MOD;

        int ng2=(g2==0)?nums[idx]:gcd(g2,nums[idx]);
        res=(res+solve(idx+1,g1,ng2))%MOD;

        return res;
    }

    int subsequencePairCount(vector<int>& a) {
        nums=a;
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};