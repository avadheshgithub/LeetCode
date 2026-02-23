class Solution {
public:
    int trapRainWater(vector<vector<int>>& Arr) {
        if (Arr.empty() || Arr[0].empty()) return 0;
        
        int m = Arr.size();
        int n = Arr[0].size();
        
        // Min heap: {height, row, col}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //Push all boundary cells
        for (int i = 0; i < m; i++) {
            pq.emplace(Arr[i][0], i, 0);
            pq.emplace(Arr[i][n-1], i, n-1);
            visited[i][0] = visited[i][n-1] = true;
        }
        
        for (int j = 0; j < n; j++) {
            pq.emplace(Arr[0][j], 0, j);
            pq.emplace(Arr[m-1][j], m-1, j);
            visited[0][j] = visited[m-1][j] = true;
        }
        
        int water = 0;
        vector<int> dir = {0,1,0,-1,0};
        
        // Process heap
        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k+1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    
                    // Water trapped
                    water += max(0, height - Arr[nx][ny]);
                    
                    // Push with updated height
                    pq.emplace(max(height, Arr[nx][ny]), nx, ny);
                }
            }
        }
        return water;
    }
};