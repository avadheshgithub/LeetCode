class Solution {
public:
    void dfs(int curr, vector<vector<int>>& grid, vector<bool>& vis) {
        vis[curr] = true;

        for(int j=0; j<grid.size(); j++) {
            if(grid[curr][j] == 1 && !vis[j]) {
                dfs(j, grid, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> vis(n, false);

        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, grid, vis);
                provinces++;
            }
        }
        return provinces;
    }
};