
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
       
        vector<vector<int>> paths(n + 1, vector<int>(n + 1, 0));
        
        dp[n - 1][n - 1] = 0;
        paths[n - 1][n - 1] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                
          
                if (board[i][j] == 'S' || board[i][j] == 'X') continue;
                
               
                int max_prev = -1;
                if (dp[i + 1][j] != -1) max_prev = max(max_prev, dp[i + 1][j]);
                if (dp[i][j + 1] != -1) max_prev = max(max_prev, dp[i][j + 1]);
                if (dp[i + 1][j + 1] != -1) max_prev = max(max_prev, dp[i + 1][j + 1]);
                
                if (max_prev != -1) {

                    int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp[i][j] = max_prev + val;
         
                    if (dp[i + 1][j] == max_prev) {
                        paths[i][j] = (paths[i][j] + paths[i + 1][j]) % MOD;
                    }
                    if (dp[i][j + 1] == max_prev) {
                        paths[i][j] = (paths[i][j] + paths[i][j + 1]) % MOD;
                    }
                    if (dp[i + 1][j + 1] == max_prev) {
                        paths[i][j] = (paths[i][j] + paths[i + 1][j + 1]) % MOD;
                    }
                }
            }
        }
        
        if (paths[0][0] == 0) {
            return {0, 0};
        }
        
        return {dp[0][0], paths[0][0]};
    }
};