class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int n = mat.size();

        auto rotate = [&](vector<vector<int>>& m) {
            vector<vector<int>> temp(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    temp[j][n-1-i] = m[i][j];
                }
            }
            m = temp;
        };

        for (int k = 0; k < 4; k++) {
            if (mat == tar) return true;
            rotate(mat);
        }
        return false;
    }
};