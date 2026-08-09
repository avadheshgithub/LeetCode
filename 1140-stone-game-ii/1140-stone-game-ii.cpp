class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> suffix_sum(n);
        suffix_sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }
        
        function<int(int, int)> solve = [&](int i, int m) {
            if (i >= n) return 0;
            if (i + 2 * m >= n) return suffix_sum[i];
            if (dp[i][m] != -1) return dp[i][m];

            int max_stones = 0;
            for (int x = 1; x <= 2 * m; ++x) {
                max_stones = max(max_stones, suffix_sum[i] - solve(i + x, max(m, x)));
            }
            return dp[i][m] = max_stones;
        };
        return solve(0, 1);
    }
};