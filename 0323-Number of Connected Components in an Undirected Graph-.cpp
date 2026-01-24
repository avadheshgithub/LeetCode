class Solution {
public:
    void dfs(int curr,vector<vector<int>>&adj,vector<bool>&vis){
        vis[curr]= true;

        for(int v : adj[curr]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        int count = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};
