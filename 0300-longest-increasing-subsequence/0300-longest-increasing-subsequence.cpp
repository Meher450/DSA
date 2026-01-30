class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // Step 1: Number of elements
        int n = nums.size();

        // Step 2: DP array
        // dp[i] = LIS length ending at index i
        vector<int> dp(n, 1);

        // Step 3: Fill DP array
        for (int i = 0; i < n; i++) {

            // Check all previous elements
            for (int j = 0; j < i; j++) {

                // If nums[i] can extend LIS ending at j
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // Step 4: The answer is the maximum value in dp[]
        return *max_element(dp.begin(), dp.end());
    }
};
