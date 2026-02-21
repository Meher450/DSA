class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();  // Store size of array
        int count = 1;  // Count keeps track of relative frequency
        int majority = nums[0];  // Assume first element as initial candidate

        // Phase 1: Moore’s Voting Algorithm to find potential majority
        for (int i = 1; i < n; i++) {
            
            if (nums[i] == majority)
                count++;  // Same as candidate → increase count
            else {
                count--;  // Different element → decrease count
                
                if (count == 0) {
                    majority = nums[i];  // Change candidate
                    count = 1;  // Reset count for new candidate
                }
            }
        }

        return majority;  // Return majority candidate
    }
};


/*
=================================
ALGORITHM USED:
Boyer–Moore Voting Algorithm
---------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

Idea:
Pairs of different elements cancel each other out.
Since majority element appears more than n/2 times,
it will remain as the final candidate.
=================================


=================================
DRY RUN (After Code Execution)
=================================

Example:
nums = [2,2,1,1,1,2,2]

Initial:
majority = 2
count = 1

i = 1 → nums[1] = 2
Same as majority → count = 2

i = 2 → nums[2] = 1
Different → count = 1

i = 3 → nums[3] = 1
Different → count = 0
count == 0 → change majority = 1, count = 1

i = 4 → nums[4] = 1
Same → count = 2

i = 5 → nums[5] = 2
Different → count = 1

i = 6 → nums[6] = 2
Different → count = 0
count == 0 → change majority = 2, count = 1

Loop Ends

Final majority candidate = 2


---------------------------------

Why It Works:

Array:
[2,2,1,1,1,2,2]

Pairs of different elements cancel each other:

(2,1)
(2,1)
(1,2)

Remaining element: 2

Since majority element appears > n/2 times,
it survives cancellation process.


---------------------------------

Note:
If problem does NOT guarantee existence of majority element,
a second pass should be added to verify count > n/2.
*/