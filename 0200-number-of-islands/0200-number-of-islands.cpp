class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j, int m, int n) {

        // Base condition: out of bounds or water
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }

        // Mark current land as visited
        grid[i][j] = '0';

        // Explore all 4 directions
        DFS(grid, i + 1, j, m, n);
        DFS(grid, i - 1, j, m, n);
        DFS(grid, i, j + 1, m, n);
        DFS(grid, i, j - 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        // Traverse entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If land is found, it's a new island
                if (grid[i][j] == '1') {
                    DFS(grid, i, j, m, n);
                    ans++;  // increment ONLY when new island is found
                }
            }
        }

        return ans;
    }
};