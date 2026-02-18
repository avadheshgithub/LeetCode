class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) return 0;
        
        grid[i][j] = 0;

        int area = 1;

        area += dfs(i-1, j, grid, n, m); // top
        area += dfs(i, j+1, grid, n, m); // right
        area += dfs(i+1, j, grid, n, m); // bottom
        area += dfs(i, j-1, grid, n, m); // left

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i, j, grid, n, m);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
