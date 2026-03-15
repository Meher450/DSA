class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0; i < 9; i++){
            // check row
            if(board[row][i] == num)
                return false;
            // check column
            if(board[i][col] == num)
                return false;
            // check 3×3 box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char num = '1'; num <= '9'; num++){
                        if(isSafe(board, row, col, num)){
                            board[row][col] = num;
                            if(solve(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

/*
APPROACH

Step 1
Find an empty cell ('.').

Step 2
Try numbers from '1' → '9'.

Step 3
Check if the number is safe:
    - row check
    - column check
    - 3×3 box check

Step 4
Place the number.

Step 5
Recursively solve the remaining board.

Step 6
If no number works → backtrack.

---------------------------------------------------------------------

DRY RUN

Example Board

5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .

---------------------------------------------------------------------

First empty cell

5 3 . | . 7 . | . . .
      ↑

Try numbers

1 ✔ safe

Place

5 3 1 | . 7 . | . . .

---------------------------------------------------------------------

Next empty cell

5 3 1 | . 7 . | . . .
        ↑

Try numbers

2 ✔ safe

Place

5 3 1 | 2 7 . | . . .

---------------------------------------------------------------------

Continue recursion until board filled.

If a dead end occurs:

Undo placement and try next number.

---------------------------------------------------------------------

VISUALIZATION

Sudoku search tree

Empty cell
   |
   ├── try 1
   │     ├── valid → continue
   │     └── dead end → backtrack
   |
   ├── try 2
   │     └── explore
   |
   └── try 3
         └── explore

---------------------------------------------------------------------

Time Complexity

Worst case ≈ O(9^(empty cells))

---------------------------------------------------------------------

Space Complexity

O(1)
(recursion depth ≤ 81)
*/