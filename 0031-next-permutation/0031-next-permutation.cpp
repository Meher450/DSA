class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find pivot
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If pivot exists, find next greater element
        if(pivot != -1) {
            for(int i = n - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // Step 3: Reverse suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};


/*
========================
DRY RUN EXAMPLE
========================

Example Input:
nums = [1, 3, 5, 4, 2]

----------------------------------------
Step 1: Find Pivot
----------------------------------------

Traverse from right:

Check i = 3
nums[3] = 4
nums[4] = 2
4 < 2 ? No

Check i = 2
nums[2] = 5
nums[3] = 4
5 < 4 ? No

Check i = 1
nums[1] = 3
nums[2] = 5
3 < 5 ? Yes

So pivot = 1

Array structure now:

[ 1 | 3 | 5 4 2 ]
      ↑
    pivot

Left side is fixed.
Right side is decreasing order.

----------------------------------------
Step 2: Find just greater element than nums[pivot]
----------------------------------------

We search from right side:

nums[pivot] = 3

Check from end:

i = 4 → nums[4] = 2 → 2 > 3 ? No
i = 3 → nums[3] = 4 → 4 > 3 ? Yes

Swap nums[1] and nums[3]

Array becomes:

[ 1 | 4 | 5 3 2 ]

----------------------------------------
Step 3: Reverse suffix (pivot+1 to end)
----------------------------------------

Suffix before reverse:
[ 5 3 2 ]

After reverse:
[ 2 3 5 ]

Final array:

[ 1 4 2 3 5 ]

----------------------------------------
Final Answer:
[1, 4, 2, 3, 5]

----------------------------------------

VISUAL SUMMARY

Original:
1 3 5 4 2
    ↑
  pivot

After swap:
1 4 5 3 2

After reverse:
1 4 2 3 5

----------------------------------------

Edge Case Example:
nums = [5,4,3,2,1]

No pivot found (fully decreasing)

Reverse entire array:

Result:
[1,2,3,4,5]

----------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)
*/