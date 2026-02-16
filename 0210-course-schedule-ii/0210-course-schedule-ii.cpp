class Solution {
public:
    bool isCycleDFS(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>&edges){
        vis[src]= true;
        recPath[src]= true;

        for(int i=0;i<edges.size();i++){ 
            int v = edges[i][0];  // [1 V,0 U] --> (0->1) U-->V
            int u = edges[i][1];

            if(u==src){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recPath,edges)) return true;
                }
                else if(recPath[v]){ //--> BackEdge Cycle
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoOrder(int src,vector<bool>&vis,stack<int>&st,vector<vector<int>>&edges){
        vis[src] = true;

        for(int i=0;i<edges.size();i++){ 
            int v = edges[i][0];  
            int u = edges[i][1];

            if(u==src){
                if(!vis[v]){
                    topoOrder(v,vis,st,edges);
                }
            }
        }
        st.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);

        for(int i=0;i<n;i++){  //--> for disconnected Graph
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,edges)) return {};
            }
        }
        
        vis.assign(n,false);
        stack<int>st;

        for(int i=0;i<n;i++){  //--> for disconnected Graph
            if(!vis[i]){
                topoOrder(i,vis,st,edges);
            }
        }

        vector<int>ans; // store ans
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};