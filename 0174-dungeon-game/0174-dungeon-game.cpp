class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        // Step 1: Dimensions of the dungeon
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Step 2: DP table
        // dp[i][j] = minimum health needed before entering cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Step 3: Base case (destination cell)
        // Need at least 1 health after this cell
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        // Step 4: Fill last column (can only move down)
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] =
                max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }

        // Step 5: Fill last row (can only move right)
        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] =
                max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        // Step 6: Fill remaining grid (bottom-up)
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {

                int minNext = min(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] =
                    max(1, minNext - dungeon[i][j]);
            }
        }

        // Step 7: Minimum initial health required
        return dp[0][0];
    }
};
