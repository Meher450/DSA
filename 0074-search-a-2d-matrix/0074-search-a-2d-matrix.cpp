class Solution {
public:
    // Binary search inside a specific row
    bool searchInRow(vector<vector<int>>& matrix, int row, int target) {

        int cols = matrix[0].size();
        int left = 0;
        int right = cols - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (target < matrix[row][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;

        // Binary search to find correct row
        while (top <= bottom) {

            int midRow = top + (bottom - top) / 2;

            // Check if target lies in this row
            if (target >= matrix[midRow][0] &&
                target <= matrix[midRow][cols - 1]) {
                return searchInRow(matrix, midRow, target);
            } else if (target < matrix[midRow][0]) {
                bottom = midRow - 1;
            } else {
                top = midRow + 1;
            }
        }

        return false;
    }
};

/*
Approach 1 Explanation

Step 1
Binary search on rows to find the row where target may exist.

Step 2
Binary search inside that row.

Time Complexity

Row Search     → O(log m)
Column Search  → O(log n)

Total          → O(log m + log n)
------------------------------------------------------------------------
APPROACH 2 BY USING SINGLE BINARY SEARCH
------------------------------------------------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Convert 1D index → 2D index
            int row = mid / cols;
            int col = mid % cols;

            int value = matrix[row][col];

            if (value == target) {
                return true;
            }
            else if (value < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};


---------------------
Dry Run Example

Matrix

1   3   5   7
10  11  16  20
23  30  34  60

target = 16

rows = 3
cols = 4

left = 0
right = 11

--------------------------------------------------

Iteration 1

mid = 5

row = 5 / 4 = 1
col = 5 % 4 = 1

matrix[1][1] = 11

11 < 16

left = mid + 1

--------------------------------------------------

Iteration 2

left = 6
right = 11

mid = 8

row = 8 / 4 = 2
col = 8 % 4 = 0

matrix[2][0] = 23

23 > 16

right = mid - 1

--------------------------------------------------

Iteration 3

left = 6
right = 7

mid = 6

row = 6 / 4 = 1
col = 6 % 4 = 2

matrix[1][2] = 16

Target Found

--------------------------------------------------

Time Complexity

Binary Search over m*n elements

O(log(m*n))

Space Complexity

O(1)

--------------------------------------------------

Index Mapping Trick

index → row, col

row = index / cols
col = index % cols
*/