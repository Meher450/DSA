class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[high--]);
            } else {
                mid++;
            }
        }
    }
};

/*
Dry Run Example:
nums = [2, 0, 2, 1, 1, 0]

Legend:
[ 0s area | 1s area | Unsorted area | 2s area ]

--------------------------------------------------
Initial State:
low=0, mid=0, high=5

[ | | 2 0 2 1 1 0 | ]
  0s 1s  Unsorted   2s

--------------------------------------------------
Step 1: nums[mid] = 2
Swap mid and high

Array: [0, 0, 2, 1, 1, 2]
low=0, mid=0, high=4

[ | | 0 0 2 1 1 | 2 ]
  0s 1s  Unsorted  2s

--------------------------------------------------
Step 2: nums[mid] = 0
Swap low and mid

Array: [0, 0, 2, 1, 1, 2]
low=1, mid=1, high=4

[ 0 | | 0 2 1 1 | 2 ]
  0s  1s  Unsorted 2s

--------------------------------------------------
Step 3: nums[mid] = 0
Swap low and mid

Array: [0, 0, 2, 1, 1, 2]
low=2, mid=2, high=4

[ 0 0 | | 2 1 1 | 2 ]
   0s    1s  Unsorted 2s

--------------------------------------------------
Step 4: nums[mid] = 2
Swap mid and high

Array: [0, 0, 1, 1, 2, 2]
low=2, mid=2, high=3

[ 0 0 | | 1 1 | 2 2 ]
   0s    1s  Unsorted 2s

--------------------------------------------------
Step 5: nums[mid] = 1
mid++

low=2, mid=3, high=3

[ 0 0 | 1 | 1 | 2 2 ]
   0s   1s  Unsorted 2s

--------------------------------------------------
Step 6: nums[mid] = 1
mid++

low=2, mid=4, high=3

Now mid > high → stop

--------------------------------------------------
Final State:
[ 0 0 | 1 1 | | 2 2 ]
   0s    1s      2s

--------------------------------------------------

Final Array:
[0, 0, 1, 1, 2, 2]


Invariant Maintained Throughout:

0 to low-1        → all 0s
low to mid-1      → all 1s
mid to high       → unknown area
high+1 to end     → all 2s
*/