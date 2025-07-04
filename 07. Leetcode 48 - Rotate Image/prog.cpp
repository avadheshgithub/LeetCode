// Rotate Image
// Leetcode Problem 48: Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        // Step 01 - transpose matrix
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Step 02 -reverse each row
        for (int k = 0; k < m; k++) {
            int i = 0;
            int j = m - 1;
            while (i < j) {
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
                i++;j--;
            }
        }
    }
};