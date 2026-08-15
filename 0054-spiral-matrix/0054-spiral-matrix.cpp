class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Left → Right
            for (int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
            top++;

            // Top → Bottom
            for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;

            // Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Bottom → Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};

/*
APPROACH

Use four boundaries to represent the remaining matrix:

top    → first remaining row
bottom → last remaining row
left   → first remaining column
right  → last remaining column

Traverse the matrix layer by layer in four directions:

1. Left → Right
2. Top → Bottom
3. Right → Left
4. Bottom → Top

After traversing each side, move that boundary inward.

--------------------------------------------------

Example

Matrix:

1  2  3
4  5  6
7  8  9

Initial:

top = 0
bottom = 2
left = 0
right = 2

--------------------------------------------------

Step 1: Left → Right

1  2  3
─────────>

ans = [1,2,3]

Move top:

top = 1

--------------------------------------------------

Step 2: Top → Bottom

3
↓
6
9

ans = [1,2,3,6,9]

Move right:

right = 1

--------------------------------------------------

Step 3: Right → Left

8 ← 7

ans = [1,2,3,6,9,8,7]

Move bottom:

bottom = 1

--------------------------------------------------

Step 4: Bottom → Top

4
↑

ans = [1,2,3,6,9,8,7,4]

Move left:

left = 1

--------------------------------------------------

Remaining Matrix:

5

ans = [1,2,3,6,9,8,7,4,5]

--------------------------------------------------

Final Answer:

[1,2,3,6,9,8,7,4,5]

--------------------------------------------------

WHY ARE THE IF CONDITIONS NEEDED?

Before traversing Right → Left:

if (top <= bottom)

This prevents traversing a row that has
already been processed.

Before traversing Bottom → Top:

if (left <= right)

This prevents traversing a column that has
already been processed.

These checks are especially important for
single-row and single-column matrices.

--------------------------------------------------

INVARIANT

At the beginning of every iteration:

top    → first unprocessed row
bottom → last unprocessed row
left   → first unprocessed column
right  → last unprocessed column

After every traversal, one boundary moves
towards the center.

--------------------------------------------------

Time Complexity:

O(m × n)

Every element is visited exactly once.

--------------------------------------------------

Space Complexity:

O(m × n)

For the output vector.

Auxiliary Space:

O(1)

--------------------------------------------------

PATTERN

Matrix Traversal
→ Boundary Traversal
→ Layer-by-Layer Traversal
*/