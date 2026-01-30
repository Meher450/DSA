class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        // Step 1: Dimensions of the matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 2: DP matrix
        // dp[i][j] stores the side length of the largest square
        // ending at cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Step 3: Track maximum square side found
        int maxSide = 0;

        // Step 4: Traverse each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Only consider cells with '1'
                if (matrix[i][j] == '1') {

                    // If in first row or first column,
                    // maximum square size is 1
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        // Take minimum of top, left, and diagonal
                        dp[i][j] = min({
                            dp[i - 1][j],
                            dp[i][j - 1],
                            dp[i - 1][j - 1]
                        }) + 1;
                    }

                    // Update maximum side length
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        // Step 5: Return area of the largest square
        return maxSide * maxSide;
    }
};
