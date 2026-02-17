class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 1;

        if (grid[i][j] == 2) return 0; // already visited

        grid[i][j] = 2; // mark visited

        int perimeter = 0;

        perimeter += dfs(i-1, j, m, n, grid);
        perimeter += dfs(i+1, j, m, n, grid);
        perimeter += dfs(i, j-1, m, n, grid);
        perimeter += dfs(i, j+1, m, n, grid);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return dfs(i, j, m, n, grid);
                }
            }
        }
        return 0;
    }
};
