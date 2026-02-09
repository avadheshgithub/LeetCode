class Solution {
public:
    int countLessEqual(const vector<vector<int>>& mat, int mid) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;

        int row = n-1;
        int col = 0;
        
        while(row>=0 && col<m){
            if(mat[row][col]<=mid){
                count += row+1;
                col++;
            }
            else row--;
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int L = mat[0][0];
        int R = mat[n-1][n-1];
        
        while(L<R){
            int mid = L+(R-L)/2;
            
            int count = countLessEqual(mat, mid);
            
            if (count<k) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};