class Solution {
public:

    bool isCycleDFS(int src, vector<bool>& vis,vector<bool>& recPath,vector<vector<int>>& adj) {

        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) { 
            if (!vis[v]) {
                if (isCycleDFS(v, vis, recPath, adj))
                    return true;
            }
            else if (recPath[v]) {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    void topoOrder(int src,vector<bool>& vis,stack<int>& st,vector<vector<int>>& adj) {

        vis[src] = true;

        for (int v : adj[src]) {  
            if (!vis[v]) {
                topoOrder(v, vis, st, adj);
            }
        }
        st.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);     // adjacency List
        for (auto &e : edges) {
            adj[e[1]].push_back(e[0]);   // u → v
        }

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for(int i=0; i<n; i++) { // Cycle Detection
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath, adj)) return {};
            }
        }

        vis.assign(n, false);
        stack<int> st;
        for(int i=0; i<n; i++) {  // Topological Sort
            if (!vis[i]) {
                topoOrder(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
