// Score after flipping a matrix
// Leetcode problem number: 861

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();

        // Step 01 - check if first element 0 --> flipping between rows
        for(int i=0;i<row;i++){
            if(grid[i][0]==0){
                for(int j=0;j<column;j++){
                    if(grid[i][j]==0) grid[i][j] = 1;
                    else grid[i][j]=0;
                }
            }
        }

        // step 02 - columnsWise if noz > noo then ---> flipping between column
        for(int j=0;j<column;j++){
            int noz=0;
            int noo=0;
            for(int i=0;i<row;i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }

            if(noz>noo){
                for(int i=0;i<row;i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j] = 0;
                }
            }
        }

        // step 03 - calculate sum
        int sum = 0;
        for(int i=0;i<row;i++){
            int x=1;
            for(int j=column-1;j>=0;j--){
                sum += grid[i][j]*x;
                x *= 2;
            }
        }

        return sum;
    }
};