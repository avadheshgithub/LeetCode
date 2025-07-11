// Search a 2D Matrix II
// Leetcode problem number: 240

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        // Approach - Two Pointer 
        int i=0;
        int j = col-1;
        while(i<row && j>=0){
            if(matrix[i][j]==target) return true;
            else if (matrix[i][j]>target) j--;
            else i++;
        }

        return false;
    }
};