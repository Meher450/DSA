class Solution {
public:
    bool canPartition(vector<int>& nums) {

        // Step 1: Calculate total sum of elements
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Step 2: If sum is odd, equal partition is impossible
        if (sum % 2 != 0) {
            return false;
        }

        // Step 3: Target sum for each subset
        int target = sum / 2;

        // Step 4: DP table
        // dp[i][j] = 1 if sum j can be formed using first i elements
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Step 5: Base case
        // Sum 0 can always be formed using any number of elements
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Step 6: Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {

                // If current number can fit in sum j
                if (j >= nums[i - 1]) {

                    // Two choices:
                    // 1. Exclude current number
                    // 2. Include current number
                    dp[i][j] = (dp[i - 1][j] ||
                                dp[i - 1][j - nums[i - 1]]);
                }
                else {
                    // Cannot include current number
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Step 7: Check if target sum is achievable
        return dp[n][target] >= 1;
    }
};
