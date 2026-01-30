class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // Step 1: Lengths of both strings
        int m = text1.size();
        int n = text2.size();

        // Step 2: DP table
        // dp[i][j] stores LCS length for
        // text1[0..i-1] and text2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 3: Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // If characters match, extend the LCS
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                // If characters don't match, take the best option
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 4: Final answer is in dp[m][n]
        return dp[m][n];
    }
};