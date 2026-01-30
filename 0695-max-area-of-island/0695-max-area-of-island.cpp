class Solution {
public:
    // DFS returns the area of the island starting at (i, j)
    int DFS(vector<vector<int>>& grid, int i, int j) {

        // Base case: out of bounds or water
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 0;
        }

        // Mark current land cell as visited
        grid[i][j] = 0;

        // Count current cell (1) + area from all 4 directions
        return 1 + DFS(grid, i + 1, j) + DFS(grid, i - 1, j) +
               DFS(grid, i, j + 1) + DFS(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        // Traverse entire grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // If land is found, calculate its island area
                if (grid[i][j] == 1) {
                    ans = max(ans, DFS(grid, i, j));
                }
            }
        }

        return ans;
    }
};