class Solution {
public:
    int rob(vector<int>& nums) {

        // Step 1: Number of houses
        int n = nums.size();

        // Step 2: Edge cases
        // If there are no houses, nothing can be robbed
        if (n <= 0) {
            return 0;
        }

        // If there is only one house, rob it
        if (n == 1) {
            return nums[0];
        }

        // Step 3: DP array
        // nums1[i] stores the maximum money that can be robbed
        // from house 0 to house i
        int nums1[n + 1];

        // Step 4: Base case initialization
        // Only first house available
        nums1[0] = nums[0];

        // Best of robbing first or second house
        nums1[1] = max(nums[1], nums[0]);

        // Step 5: Fill DP array
        for (int i = 2; i < n; i++) {

            // Choice:
            // 1. Skip current house -> nums1[i-1]
            // 2. Rob current house -> nums[i] + nums1[i-2]
            nums1[i] = max(nums1[i - 1], nums[i] + nums1[i - 2]);
        }

        // Step 6: The last value contains the answer
        return nums1[n - 1];
    }
};