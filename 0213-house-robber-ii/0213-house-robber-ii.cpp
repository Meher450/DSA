class Solution {
public:
    int rob(vector<int>& nums) {

        // Step 1: Number of houses
        int n = nums.size();

        // Step 2: Edge cases
        // No houses -> no money
        if (n <= 0) return 0;

        // Only one house -> rob it
        if (n == 1) return nums[0];

        // --------------------------------------------------
        // Case 1: Exclude first house, consider houses [1..n-1]
        // --------------------------------------------------

        // dp[i] stores max money robbed till house i
        int dp[n];

        // Since we exclude the first house:
        // dp[0] represents a dummy value
        dp[0] = 0;

        // Only house 1 is considered initially
        dp[1] = nums[1];

        for (int i = 2; i < n; i++) {

            // Either skip current house
            // Or rob it and add dp[i-2]
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        // --------------------------------------------------
        // Case 2: Exclude last house, consider houses [0..n-2]
        // --------------------------------------------------

        int dp1[n];

        // First house can be robbed
        dp1[0] = nums[0];

        // Choose max of robbing first or second house
        dp1[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {

            // Either skip current house
            // Or rob it and add dp1[i-2]
            dp1[i] = max(dp1[i - 1], nums[i] + dp1[i - 2]);
        }

        // Step 3: Return the maximum of both cases
        return max(dp1[n - 2], dp[n - 1]);
    }
};
