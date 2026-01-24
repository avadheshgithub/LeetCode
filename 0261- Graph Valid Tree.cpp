class Solution {
public:
    void isConnected(int curr,vector<vector<int>>&adj,vector<bool>&vis){
        vis[curr]= true;

        for(int v : adj[curr]){
            if(!vis[v]){
                isConnected(v,adj,vis);
            }
        }
    }

    bool isCycle(int src, int par,vector<vector<int>>&adj,vector<bool>&seen){
        seen[src] = true;

        for(int v:adj[src]){
            if(!seen[v]){
                if(isCycle(v,src,adj,seen)) return true;
            }
            else if(v!=par){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
       vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1. check Disconnected
        vector<bool>vis(n,false);
        int NumOfDisConnected = 0 ;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                isConnected(i,adj,vis);
                NumOfDisConnected++;
            }
            if(NumOfDisConnected>1) return false;
        }

        // 2. isCycle
        vector<bool>seen(n,false);
        if(isCycle(0,-1,adj,seen)) return false;

        return true;
    }
};
