class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int idx = q.front();
                q.pop();

                if (idx == n - 1)
                    return steps;

                vector<int> neigh;

                for (int x : mp[arr[idx]]) {
                    neigh.push_back(x);
                }

                neigh.push_back(idx - 1);
                neigh.push_back(idx + 1);

                for (int next : neigh) {
                    if (next >= 0 && next < n && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                mp[arr[idx]].clear();
            }
            steps++;
        }
        return -1;
    }
};