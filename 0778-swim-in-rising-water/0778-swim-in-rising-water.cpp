class Solution {
public:

    // DFS to check if destination is reachable at given time
    bool DFS(vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             int i, int j, int time) {

        int n = grid.size();

        // Base cases:
        // 1. Out of bounds
        // 2. Already visited
        // 3. Cell is above current water level
        if (i < 0 || j < 0 || i >= n || j >= n ||
            visited[i][j] == true ||
            grid[i][j] > time) {
            return false;
        }

        // If destination is reached
        if (i == n - 1 && j == n - 1) {
            return true;
        }

        // Mark current cell as visited
        visited[i][j] = true;

        // Explore all 4 directions
        return DFS(grid, visited, i + 1, j, time) ||
               DFS(grid, visited, i - 1, j, time) ||
               DFS(grid, visited, i, j + 1, time) ||
               DFS(grid, visited, i, j - 1, time);
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        // Binary search range for time
        int low = 0, high = n * n;

        while (low < high) {

            int mid = (low + high) / 2;

            // Visited array for DFS
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            // If path exists at time = mid
            if (DFS(grid, visited, 0, 0, mid)) {
                high = mid;   // try smaller time
            } else {
                low = mid + 1; // need more time
            }
        }

        // Minimum time required
        return low;
    }
};
