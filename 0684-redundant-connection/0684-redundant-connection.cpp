class Solution {
public:
    int find(int x, vector<int>& parent) {
        while(x != parent[x]) {
            parent[x] = parent[parent[x]]; 
            x = parent[x];
        }
        return x;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);

        for(int i=1; i<=n; i++) {
            parent[i] = i; // every node is parent of its own
        }

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            if(pu == pv) return e; // same parent --> cycle detected

            parent[pv] = pu; // update the parent after merge
        }
        return {-1};
    }
};