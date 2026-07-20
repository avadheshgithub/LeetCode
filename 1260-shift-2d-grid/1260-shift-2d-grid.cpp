class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalCells = m * n;
        
        k = k % totalCells;
        
        if (k == 0) {
            return grid;
        }
        
        vector<vector<int>> result(m,vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = i * n + j;
                
                int new_p = (p + k) % totalCells;
                
                result[new_p / n][new_p % n] = grid[i][j];
            }
        }
        
        return result;
    }
};