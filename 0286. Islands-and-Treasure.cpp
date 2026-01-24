class Solution {
public:
    const int INF = 2147483647;
    int dir[5] = {0, 1, 0, -1, 0};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // push all gates
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // BFS from all gates together
        while(!q.empty()) {
            auto gate = q.front();
            q.pop();

            int row = gate.first;
            int col = gate.second;

            for(int i = 0; i < 4; i++) { // Explore all 4 direction
                int NR = row + dir[i];
                int NC = col + dir[i+1];

                if(NR>=0 && NR<m && NC>=0 && NC<n && grid[NR][NC]==INF) {
                    grid[NR][NC] = grid[row][col] + 1;
                    q.push({NR, NC});
                }
            }
        }
    }
};
