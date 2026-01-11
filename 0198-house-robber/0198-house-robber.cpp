class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return arr[0];  

        vector<int>dp(n);
     
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-1],arr[n-2]);

        for(int i = n-3; i>=0;i--){
            dp[i] = max(arr[i]+dp[i+2],0+dp[i+1]);
        }

        return dp[0];
    }
};