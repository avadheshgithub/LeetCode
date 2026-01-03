class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        int m = N; int n = N;

        int sRow=0 , Scol=0, eRow=m-1, eCol=n-1;
        int TNE=n*m, count=0;
        
        vector<vector<int>>matrix(N,vector<int>(N));

        while(sRow<=eRow && Scol<=eCol){
            //right
            for(int j=Scol;j<=eCol && count<TNE;j++){
                count++;
                matrix[sRow][j]=count;
            }
            sRow++;

            //down
            for(int i=sRow;i<=eRow && count<TNE;i++){
                count++;
                matrix[i][eCol]=count;
            }
            eCol--;

            // left
            for(int j=eCol;j>=Scol && count<TNE;j--){
                count++;
                matrix[eRow][j]=count;
            }
            eRow--;

            // up
            for(int i=eRow;i>=sRow && count<TNE;i--){
                count++;
                matrix[i][Scol]=count;
                
            }
            Scol++;
        }
        return matrix;
    }
};