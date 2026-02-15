class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<bool>>&vis,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]!='1') return ;

        vis[i][j] = true; 

        dfs(i-1,j,m,n,vis,grid); //up
        dfs(i,j+1,m,n,vis,grid); //right
        dfs(i+1,j,m,n,vis,grid); //bottom
        dfs(i,j-1,m,n,vis,grid); //left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        int island = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,m,n,vis,grid);
                    island++;
                }
            }
        }
        return island;
    }
};