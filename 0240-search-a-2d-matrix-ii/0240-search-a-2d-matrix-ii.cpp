class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Start from top-right corner
        int row = 0;
        int col = cols - 1;

        while (row < rows && col >= 0) {

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;   // move left
            }
            else {
                row++;   // move down
            }
        }

        return false;
    }
};


/*
Matrix Properties

1. Each row is sorted left → right
2. Each column is sorted top → bottom

Example Matrix

[
 [1, 4, 7, 11, 15],
 [2, 5, 8, 12, 19],
 [3, 6, 9, 16, 22],
 [10,13,14,17,24],
 [18,21,23,26,30]
]


--------------------------------------------------
Dry Run Example

target = 10

Start at TOP-RIGHT corner

row = 0
col = 4

Current value = 15

--------------------------------------------------
Step 1

matrix[0][4] = 15

15 > 10

Move LEFT

row = 0
col = 3


Matrix View

1   4   7  [11]  15
2   5   8   12   19
3   6   9   16   22
10 13  14   17   24
18 21  23   26   30


--------------------------------------------------
Step 2

matrix[0][3] = 11

11 > 10

Move LEFT

row = 0
col = 2


Matrix View

1   4  [7]  11  15
2   5   8   12  19
3   6   9   16  22
10 13  14   17  24
18 21  23   26  30


--------------------------------------------------
Step 3

matrix[0][2] = 7

7 < 10

Move DOWN

row = 1
col = 2


--------------------------------------------------
Step 4

matrix[1][2] = 8

8 < 10

Move DOWN

row = 2
col = 2


--------------------------------------------------
Step 5

matrix[2][2] = 9

9 < 10

Move DOWN

row = 3
col = 2


--------------------------------------------------
Step 6

matrix[3][2] = 14

14 > 10

Move LEFT

row = 3
col = 1


--------------------------------------------------
Step 7

matrix[3][1] = 13

13 > 10

Move LEFT

row = 3
col = 0


--------------------------------------------------
Step 8

matrix[3][0] = 10

Target Found 🎯


--------------------------------------------------
Final Result

Return true


--------------------------------------------------
Movement Logic

Start at TOP-RIGHT

matrix[row][col] > target
→ move LEFT

matrix[row][col] < target
→ move DOWN


--------------------------------------------------
Why This Works

From top-right:

LEFT  → smaller numbers
DOWN  → larger numbers

So every step eliminates either a row or a column.


--------------------------------------------------
Time Complexity

Worst case moves:

rows + cols

O(m + n)


Space Complexity

O(1)
*/