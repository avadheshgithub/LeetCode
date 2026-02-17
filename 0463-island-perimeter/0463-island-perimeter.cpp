class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& grid,vector<vector<bool>>& vis) {
        
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return 1;

        if (vis[i][j]) return 0; // alreadt visited --> contibute 0

        vis[i][j] = true;

        int perimeter = 0;

        perimeter += dfs(i-1, j, m, n, grid, vis); // up
        perimeter += dfs(i+1, j, m, n, grid, vis); // down
        perimeter += dfs(i, j-1, m, n, grid, vis); // left
        perimeter += dfs(i, j+1, m, n, grid, vis); // right

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return dfs(i, j, m, n, grid, vis);
                }
            }
        }

        return 0;
    }
};
