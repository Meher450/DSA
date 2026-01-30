class Solution {
public:
    int minDistance(string word1, string word2) {

        // Step 1: Lengths of both strings
        int m = word1.size();
        int n = word2.size();

        // Step 2: DP table for LCS
        // dp[i][j] = LCS length of word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 3: Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // If characters match, extend LCS
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // Otherwise, take max of skipping one character
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 4: Minimum deletions required
        return m + n - (2 * dp[m][n]);
    }
};
