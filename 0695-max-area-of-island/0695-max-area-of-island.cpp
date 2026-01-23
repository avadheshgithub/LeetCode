class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>&vis,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1 || vis[i][j]) return 0;

        vis[i][j]= true;
        int area = 1;

        area += dfs(i-1, j,  grid,vis,n,m); // top
        area += dfs(i,   j+1, grid,vis,n,m); // right
        area += dfs(i+1, j,  grid,vis,n,m); // bottom
        area += dfs(i,   j-1, grid,vis,n,m); // left

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area = dfs(i,j,grid,vis,n,m);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};