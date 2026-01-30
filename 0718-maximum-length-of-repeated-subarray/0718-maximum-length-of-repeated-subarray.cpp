class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        // Step 1: Sizes of both arrays
        int m = nums1.size();
        int n = nums2.size();

        // Step 2: Variable to track maximum subarray length
        int ans = 0;

        // Step 3: DP table
        // dp[i][j] = length of longest common subarray
        // ending at nums1[i-1] and nums2[j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 4: Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // If elements match, extend the subarray
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    // Update maximum length
                    ans = max(ans, dp[i][j]);
                }
                // If elements don't match, reset length
                else {
                    dp[i][j] = 0;
                }
            }
        }

        // Step 5: Return maximum subarray length
        return ans;
    }
};
