class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();  // Store size of array
        int currentSum = 0, maxSum = INT_MIN;  // currentSum tracks running sum, maxSum tracks best result
        
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];  // Add current element to running subarray sum
            
            maxSum = max(maxSum, currentSum);  // Update maximum subarray sum if needed
            
            if (currentSum < 0) 
                currentSum = 0;  // Reset if sum becomes negative (no benefit carrying it forward)
        }
        
        return maxSum;  // Return the maximum subarray sum found
    }
};


/*
=================================
ALGORITHM USED:
Kadane’s Algorithm
---------------------------------
Type: Greedy + Dynamic Programming Insight
Time Complexity: O(n)
Space Complexity: O(1)

Idea:
At each index, maintain the maximum subarray ending at that index.
If the running sum becomes negative, discard it and start fresh.
=================================


=================================
DRY RUN (After Code Execution)
=================================

Example 1:
nums = [-2,1,-3,4,-1,2,1,-5,4]

Initial:
currentSum = 0
maxSum = INT_MIN

i = 0 (-2)
currentSum = -2
maxSum = -2
currentSum < 0 → reset to 0

i = 1 (1)
currentSum = 1
maxSum = 1

i = 2 (-3)
currentSum = -2
maxSum = 1
currentSum < 0 → reset to 0

i = 3 (4)
currentSum = 4
maxSum = 4

i = 4 (-1)
currentSum = 3
maxSum = 4

i = 5 (2)
currentSum = 5
maxSum = 5

i = 6 (1)
currentSum = 6
maxSum = 6

i = 7 (-5)
currentSum = 1
maxSum = 6

i = 8 (4)
currentSum = 5
maxSum = 6

Final Answer:
6

Maximum Subarray:
[4, -1, 2, 1]


---------------------------------

Example 2:
nums = [-3,-2,-5]

i = 0 → currentSum = -3 → maxSum = -3 → reset to 0
i = 1 → currentSum = -2 → maxSum = -2 → reset to 0
i = 2 → currentSum = -5 → maxSum = -2 → reset to 0

Final Answer:
-2
(Highest single element since all numbers are negative)
*/