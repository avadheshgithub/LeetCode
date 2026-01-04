class Solution {
public:
    int m,n;
    int t[201][201];

    vector<vector<int>>direction = {
               {-1,0},
        {0,-1},        {0,1},
                {1,0}
    };

    bool isSafe(int i,int j){
        return (i<m && i>=0 && j<n && j>=0);
    }

    int dfs(vector<vector<int>>& grid,int i, int j){
        if(t[i][j]!=-1) return t[i][j];
        int count = 1; // Self Element
        for(auto &dir:direction){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(isSafe(i_,j_) && grid[i_][j_] > grid[i][j]){
               count = max(count,1 + dfs(grid,i_,j_));
            }
        }
        return t[i][j]=count;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        memset(t,-1,sizeof(t));

        int result = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result = max(result,dfs(matrix,i,j));
            }
        }  
        return result;  
    }
};