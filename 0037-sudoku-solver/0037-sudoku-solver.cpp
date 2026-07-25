class Solution {
    private:
    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
      for(int i=0;i<9;i++)
      {
        if(board[i][col]==c)
        return false;
      }
      for(int j=0;j<9;j++)
      {
        if(board[row][j]==c)
        return false;
      }
      int boxRowStart=3*(row/3);
      int boxColStart=3*(col/3);
      for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
        {
            if(board[boxRowStart+i][boxColStart+j]==c)
            return  false;
        }
      }
      return true;
    }

public:
void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;

                        solveSudoku(board);

                        // If the recursion solved the entire board, we shouldn't backtrack!
                        // Check if a cell downstream is still empty:
                        bool isStillSolving = false;
                        for (int r = 0; r < 9 && !isStillSolving; r++) {
                            for (int k = 0; k < 9; k++) {
                                if (board[r][k] == '.') {
                                    isStillSolving = true;
                                    break;
                                }
                            }
                        }

                        if (!isStillSolving) return; // Puzzle is done!

                        board[i][j] = '.'; // Backtrack
                    }
                }
                return;
            }
        }
    }
    }
};
    