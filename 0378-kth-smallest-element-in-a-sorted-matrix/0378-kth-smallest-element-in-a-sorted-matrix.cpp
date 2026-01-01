class Solution {
public:
    int countLessEqual(const vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int cnt = 0;
        
        for (int i=0,j=n-1;i<n && j>=0;){
            if (mat[i][j] <= x) {
                cnt += j + 1;
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int L = matrix[0][0];
        int R = matrix[n-1][n-1];
        
        while(L<R){
            int mid = L+(R-L)/2;
            
            int count = countLessEqual(matrix, mid);
            
            if (count<k) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};