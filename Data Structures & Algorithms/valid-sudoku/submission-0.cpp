class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9], col[9], grid[9];
        for(int i = 0; i < 9; i++) {
            row[i] = 0;
            col[i] = 0;
            grid[i] = 0;
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(row[i] & (1 << (board[i][j] - '1'))) return false;
                if(col[j] & (1 << (board[i][j] - '1'))) return false;
                if(grid[i / 3 * 3 + j / 3] & (1 << (board[i][j] - '1'))) return false;
                row[i] |= (1 << (board[i][j] - '1'));
                col[j] |= (1 << (board[i][j] - '1'));
                grid[i / 3 * 3 + j / 3] |= (1 << (board[i][j] - '1'));
            }
        }
        return true;
    }
};
