class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Check if start or end is blocked
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        // Step 2: 8 possible directions
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

        // Step 3: BFS queue
        queue<pair<int,int>> q;
        q.push({0, 0});

        // Mark start as visited with distance = 1
        grid[0][0] = 1;

        // Step 4: BFS traversal
        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            // If destination reached, return distance
            if (x == m - 1 && y == n - 1)
                return grid[x][y];

            // Explore all 8 directions
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Valid and unvisited cell
                if (nx >= 0 && ny >= 0 &&
                    nx < m && ny < n &&
                    grid[nx][ny] == 0) {

                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // No path found
        return -1;
    }
};
