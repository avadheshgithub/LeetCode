// Sudoku Solver
// Leetcode 37

// time complexity: O(9^(n*n)) where n is the size of the board (9x9)
// space complexity: O(1) since we are not using any extra space that grows with input size




class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig){
        // horizontal
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }

        // vertically
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }

        // grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;

        for(int i=srow;i<=srow+2;i++){
            for(int j=scol;j<=scol+2;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>&board,int row,int col){
        if(row==9){
            return true;
        }

        int nextRow=row, nextCol = col+1;
        if(nextCol==9){
            nextRow = row+1;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return helper(board,nextRow,nextCol);
        }

        // place the digit
        for(char dig='1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col]=dig;
                if(helper(board,nextRow,nextCol)){
                    return true;
                }
                board[row][col] = '.'; // backTrack
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};