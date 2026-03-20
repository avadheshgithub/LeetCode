class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                
                set<int> s;  // 🔥 use set to keep distinct values
                
                for(int x = i; x < i + k; x++) {
                    for(int y = j; y < j + k; y++) {
                        s.insert(grid[x][y]);
                    }
                }
                
                // convert set → vector
                vector<int> v(s.begin(), s.end());
                
                int minDiff = INT_MAX;
                
                if(v.size() == 1) {
                    minDiff = 0;
                } else {
                    for(int t = 1; t < v.size(); t++) {
                        minDiff = min(minDiff, v[t] - v[t-1]);
                    }
                }
                
                ans[i][j] = minDiff;
            }
        }
        
        return ans;
    }
};