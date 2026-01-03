class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Initialize hash sets for rows, columns, and 3x3 boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char digit = board[i][j];
                if (digit == '.') continue; 
                
                // Check row
                if (rows[i].count(digit)) return false; // Duplicate in row
                rows[i].insert(digit);
                
                // Check column
                if (cols[j].count(digit)) return false; // Duplicate in column
                cols[j].insert(digit);
                
                // Check 3x3 box
                int idx = (i / 3) * 3 + j / 3; // Map (i,j) to box index
                if (boxes[idx].count(digit)) return false; // Duplicate in box
                boxes[idx].insert(digit);
            }
        }
        return true; 
    }
};