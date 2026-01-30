class Solution {
public:
    int minDistance(string word1, string word2) {

        // Step 1: Lengths of both strings
        int m = word1.size();
        int n = word2.size();

        // Step 2: DP table
        // dp[i][j] = min operations to convert
        // word1[0..i-1] → word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 3: Base cases
        // Convert word1 prefix to empty string (delete all)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 1 + dp[i - 1][0];
        }

        // Convert empty string to word2 prefix (insert all)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = 1 + dp[0][j - 1];
        }

        // Step 4: Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // If characters match, no operation needed
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Otherwise, try all three operations
                else {
                    dp[i][j] =
                        min({
                            dp[i - 1][j - 1], // replace
                            dp[i - 1][j],     // delete
                            dp[i][j - 1]      // insert
                        }) + 1;
                }
            }
        }

        // (Optional) Debug print of DP table
        // Should be removed in final submission
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        // Step 5: Final answer
        return dp[m][n];
    }
};
//refer notes