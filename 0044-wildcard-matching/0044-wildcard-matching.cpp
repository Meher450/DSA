class Solution {
public:
    bool isMatch(string s, string p) {

        // Step 1: Lengths
        int m = s.size();
        int n = p.size();

        // Step 2: DP table
        // dp[i][j] = whether s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Step 3: Empty string matches empty pattern
        dp[0][0] = true;

        // Step 4: Handle patterns like "*", "**", "***"
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        // Step 5: Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Exact match or '?'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // '*': empty OR consume character
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                // No match
                else {
                    dp[i][j] = false;
                }
            }
        }

        // Step 6: Final answer
        return dp[m][n];
    }
};
