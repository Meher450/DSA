class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        // check column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q')
                return false;
        }

        // check left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }

        // check right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n){
        // all queens placed
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(row + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

/*
APPROACH

Step 1
Place queens row by row.

Step 2
For each column check if it is safe.

Step 3
If safe → place queen.

Step 4
Recursively solve next row.

Step 5
Backtrack (remove queen).

---------------------------------------------------------------------

Example

n = 4

Initial Board

. . . .
. . . .
. . . .
. . . .

---------------------------------------------------------------------

Place queen in row 0

Q . . .
. . . .
. . . .
. . . .

---------------------------------------------------------------------

Row 1 possibilities

Column 0 ❌ (same column)
Column 1 ❌ (diagonal)
Column 2 ✔

Q . . .
. . Q .
. . . .
. . . .

---------------------------------------------------------------------

Row 2 possibilities

Column 0 ❌
Column 1 ❌
Column 2 ❌
Column 3 ✔

Q . . .
. . Q .
. . . Q
. . . .

---------------------------------------------------------------------

Row 3 possibilities

Column 1 ✔

Q . . .
. . Q .
. . . Q
. Q . .

Solution Found

---------------------------------------------------------------------

VISUALIZATION

Board coordinates

(row , col)

Row placement tree

Row0
  ├── Col0
  │     ├── Col2
  │     │     └── Col3
  │     │            └── Col1   ✔
  │
  ├── Col1
  │
  ├── Col2
  │
  └── Col3

---------------------------------------------------------------------

Final Solutions for n = 4

Solution 1

. Q . .
. . . Q
Q . . .
. . Q .

Solution 2

. . Q .
Q . . .
. . . Q
. Q . .

---------------------------------------------------------------------

Time Complexity

≈ O(N!)

---------------------------------------------------------------------

Space Complexity

O(N)
(recursion stack)
*/