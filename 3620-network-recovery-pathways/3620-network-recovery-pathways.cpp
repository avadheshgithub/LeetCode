class Solution {
public:
    bool check(int score,
               vector<vector<int>>& edges,
               vector<bool>& online,
               long long k,
               int n) {

        vector<vector<pair<int,int>>> g(n);
        vector<int> indeg(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (w < score) continue;

            if (v != n - 1 && !online[v]) continue;
            if (u != 0 && !online[u]) continue;

            g[u].push_back({v, w});
            indeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : g[u]) {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        const long long INF = 4e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;

            for (auto &[v, w] : g[u]) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        int lo = 0, hi = 0;
        for (auto &e : edges)
            hi = max(hi, e[2]);

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, edges, online, k, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};