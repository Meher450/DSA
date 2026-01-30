class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Step 1: Initialize answer and DP variables
        int maxProd = nums[0];  // max product ending at current index
        int minProd = nums[0];  // min product ending at current index
        int ans = nums[0];      // global maximum product

        // Step 2: Traverse array from index 1
        for (int i = 1; i < nums.size(); i++) {

            int curr = nums[i];

            // Step 3: Store previous maxProd because it will be overwritten
            int prevMax = maxProd;

            // Step 4: Update max and min product
            maxProd = max({curr, curr * maxProd, curr * minProd});
            minProd = min({curr, curr * prevMax, curr * minProd});

            // Step 5: Update global answer
            ans = max(ans, maxProd);
        }

        return ans;
    }
};
