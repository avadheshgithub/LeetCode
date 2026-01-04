class Solution {
public:
    int m,n;
    int t[1001][1001];
   const long long MOD =1e9+7;

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
                count = (count + dfs(grid,i_,j_))%MOD;
            }
        }
        return t[i][j]=count;
    }

    int countPaths(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        memset(t,-1,sizeof(t));

        int result = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result = (result + dfs(matrix,i,j))%MOD;
            }
        }  
        return result;  
    }
};