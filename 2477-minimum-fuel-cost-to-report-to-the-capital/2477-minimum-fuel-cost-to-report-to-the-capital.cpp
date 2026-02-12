class Solution {
public:
    long long car = 0;

    long long dfs(vector<vector<int>>& adj, vector<bool>& vis, int start, int seats) {
        vis[start] = true;
        long long people = 1;   // each city 1 people

        for (int neb : adj[start]) {
            if (!vis[neb]) {
                people += dfs(adj, vis, neb, seats);
            }
        }

        if (start != 0) {
            car += people/seats;        //Ex - 7 people && 3 seats
            if(people%seats!=0) car++;  // 1 poeple left --> ans++
        }
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        
        for (auto& r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        vector<bool> vis(n, false);
        dfs(adj, vis, 0, seats);

        return car;
    }
};
