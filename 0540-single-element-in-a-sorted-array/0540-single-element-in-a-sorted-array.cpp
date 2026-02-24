class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;

            // Ensure mid is even (to compare with mid+1)
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Pair is correct → single is after this
                left = mid + 2;
            } else {
                // Pair is broken → single is at mid or before
                right = mid;
            }
        }
        return nums[left];
    }
};

/*
---------------------
DRY RUN
---------------------

nums = [1,1,2,3,3,4,4,8,8]

left = 0, right = 8

Iteration 1:
mid = 4
mid is even → OK
nums[4] == nums[5]? (3 == 4) → NO
→ single is left side
right = 4

left = 0, right = 4

Iteration 2:
mid = 2
nums[2] == nums[3]? (2 == 3) → NO
→ single is left side
right = 2

left = 0, right = 2

Iteration 3:
mid = 0
nums[0] == nums[1]? (1 == 1) → YES
→ single is right side
left = 2

left = 2, right = 2 → stop

Answer = nums[2] = 2
*/