class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Store the number of servers in each row and column
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // First traversal: Calculate row and column frequencies
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int counter = 0;

        // Second traversal: Count communicating servers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 &&
                    (row[i] > 1 || col[j] > 1)) {

                    counter++;
                }
            }
        }

        return counter;
    }
};

/*
APPROACH:
1. Find the dimensions of the grid:
      m = Number of rows
      n = Number of columns

2. Create two frequency arrays:
      row[m] = Number of servers in each row.
      col[n] = Number of servers in each column.

3. FIRST TRAVERSAL:
   - Traverse every cell in the grid.
   - If grid[i][j] == 1:
       Increment row[i].
       Increment col[j].

4. SECOND TRAVERSAL:
   - Traverse the grid again.
   - Check whether the current cell contains a server.
   - A server can communicate if:
       row[i] > 1 OR col[j] > 1.
   - If either condition is true, increment counter.

5. Return counter.

WHY THIS WORKS:
According to the problem, two servers can communicate
if they are located in the same row or the same column.

A server at position (i, j) can communicate if:
   - Its row contains more than one server, OR
   - Its column contains more than one server.

By calculating row and column frequencies beforehand,
we can determine whether each server can communicate
in constant time.

DRY RUN:
Input:
grid = [
    [1, 0, 1],
    [0, 1, 0],
    [0, 0, 1]
]

FIRST TRAVERSAL:

Server positions:
   (0,0), (0,2), (1,1), (2,2)

Row frequencies:
   row = [2, 1, 1]

Column frequencies:
   col = [1, 1, 2]

SECOND TRAVERSAL:

Server (0,0):
   row[0] = 2
   Communicates → counter = 1

Server (0,2):
   row[0] = 2
   Communicates → counter = 2

Server (1,1):
   row[1] = 1
   col[1] = 1
   Cannot communicate → counter = 2

Server (2,2):
   col[2] = 2
   Communicates → counter = 3

Output:
   3

COMPLEXITY:
Let:
   m = Number of rows
   n = Number of columns

Time Complexity:
   - First traversal: O(m × n)
   - Second traversal: O(m × n)
   - Overall: O(m × n)

Space Complexity:
   - Row frequency array: O(m)
   - Column frequency array: O(n)
   - Overall: O(m + n)

PATTERN:
Matrix Traversal + Frequency Counting + Hashing Concept
*/