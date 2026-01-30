class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        // Step 1: Grid dimensions
        int m = grid.size();
        int n = grid[0].size();

        // Step 2: Perimeter counter
        int peri = 0;

        // Step 3: Traverse the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If current cell is land
                if (grid[i][j] == 1) {

                    // Each land cell contributes 4 edges
                    peri += 4;

                    // If top neighbor is land, shared edge
                    if (i > 0 && grid[i - 1][j] == 1) {
                        peri -= 2;
                    }

                    // If left neighbor is land, shared edge
                    if (j > 0 && grid[i][j - 1] == 1) {
                        peri -= 2;
                    }
                }
            }
        }

        // Step 4: Return total perimeter
        return peri;
    }
};