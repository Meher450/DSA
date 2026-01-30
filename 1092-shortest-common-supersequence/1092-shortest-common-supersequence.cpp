class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        // Step 1: Lengths of both strings
        int m = str1.size();
        int n = str2.size();

        // Step 2: LCS DP table
        // dp[i][j] = LCS length of str1[0..i-1] and str2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 3: Fill the LCS DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 4: Build SCS by backtracking from dp[m][n]
        string ans;
        ans.reserve(m + n);  // Optimization

        int i = m, j = n;

        while (i > 0 && j > 0) {

            // If characters match, include it once
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            // If LCS comes from top, take char from str1
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            }
            // Otherwise, take char from str2
            else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        // Step 5: Add remaining characters from str1
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }

        // Step 6: Add remaining characters from str2
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        // Step 7: Reverse because we built the answer backward
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
