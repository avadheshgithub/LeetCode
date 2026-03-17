class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        // Step 1: Build heights
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    A[i][j] += A[i - 1][j];
                }
            }
        }

        int maxArea = 0;

        // Step 2: Process each row
        for (int i = 0; i < n; i++) {
            vector<int> height = A[i];

            // Sort descending
            sort(height.begin(), height.end(), greater<int>());

            // Calculate max area
            for (int j = 0; j < m; j++) {
                int area = height[j] * (j + 1);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};