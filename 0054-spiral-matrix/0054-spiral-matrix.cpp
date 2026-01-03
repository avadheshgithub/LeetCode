class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int sRow=0 , Scol=0, eRow=m-1, eCol=n-1;
        int tne=n*m, count=0;
        
        vector<int>vec;

        while(sRow<=eRow && Scol<=eCol){
            //right
            for(int j=Scol;j<=eCol && count<tne;j++){
                vec.push_back(matrix[sRow][j]);
                count++;
            }
            sRow++;

            //down
            for(int i=sRow;i<=eRow && count<tne;i++){
                vec.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;

            // left
            for(int j=eCol;j>=Scol && count<tne;j--){
                vec.push_back(matrix[eRow][j]);
                count++;
            }
            eRow--;

            // up
            for(int i=eRow;i>=sRow && count<tne;i--){
                vec.push_back(matrix[i][Scol]);
                count++;
            }
            Scol++;
        }
        return vec;
    }
};