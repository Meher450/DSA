class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int majority =
            nums[0]; // Assume the first element as majority candidate

        // Phase 1: Find a potential candidate using Moore’s Voting Algorithm
        for (int i = 1; i < n; i++) {
            if (nums[i] == majority)
                count++; // Same as candidate ? increase count
            else {
                count--; // Different element ? decrease count
                if (count == 0) {
                    majority = nums[i]; // Change candidate
                    count = 1;
                }
            }
        }
        return majority;
    }
};