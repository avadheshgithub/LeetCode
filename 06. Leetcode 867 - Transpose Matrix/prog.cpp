// Transpose matrix
// Leetcode problem number: 867
// Leetcode problem name: Transpose Matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 

        // Initialize result vector with n rows and m columns
        vector<vector<int>> vec(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec[i][j] = matrix[j][i];
            }
        }
        return vec;
    }
};