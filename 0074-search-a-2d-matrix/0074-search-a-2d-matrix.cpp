class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size();

        int i=0,j=n-1;
        while(i<m && j>=0){
            if(tar==mat[i][j]) return true;
            else if(tar<mat[i][j]) j--;
            else i++;
        }
        return false;
    }
};