class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0) return 0;

        int fish = grid[i][j];

        // mark visited
        grid[i][j] = 0;

        fish += dfs(i-1, j, grid, n, m);
        fish += dfs(i+1, j, grid, n, m);
        fish += dfs(i, j-1, grid, n, m);
        fish += dfs(i, j+1, grid, n, m);

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    maxFish = max(maxFish, dfs(i, j, grid, n, m));
                }
            }
        }

        return maxFish;
    }
};
