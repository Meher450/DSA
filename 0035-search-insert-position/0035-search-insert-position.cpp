class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Find the middle index.
            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target)
                return mid;

            // Target lies in the left half.
            if (nums[mid] > target) {
                right = mid - 1;
            }
            // Target lies in the right half.
            else {
                left = mid + 1;
            }
        }

        // Target not found.
        // 'left' is the correct insertion position.
        return left;
    }
};

/*
Dry Run Example:
nums = [1, 3, 5, 6]
target = 2

Legend:
Target Search Range = [left ... right]

--------------------------------------------------
Initial State:

left = 0
right = 3

Array:
Index : 0  1  2  3
Value : 1  3  5  6

Search Range:
[ 1  3  5  6 ]
  ^         ^
 left     right

--------------------------------------------------
Step 1:

mid = 0 + (3-0)/2 = 1
nums[mid] = 3

3 > 2

Discard right half.

right = mid - 1 = 0

Search Range:

[ 1 ]
  ^
left,right

--------------------------------------------------
Step 2:

left = 0
right = 0

mid = 0

nums[mid] = 1

1 < 2

Discard left half.

left = mid + 1 = 1

--------------------------------------------------
Loop Ends

left = 1
right = 0

Condition:
left > right

Search space is empty.

--------------------------------------------------
Final State

Array:

Index : 0  1  2  3
Value : 1  3  5  6

Insertion Position:

1  |  2  |  3  5  6
      ^
    index = 1

Return:

1

--------------------------------------------------

Another Example:

nums = [1,3,5,6]
target = 7

Final values:

left = 4
right = 3

Insertion:

1 3 5 6 | 7
          ^
        index = 4

Return:

4

--------------------------------------------------

Another Example:

nums = [1,3,5,6]
target = 0

Final values:

left = 0
right = -1

Insertion:

0 | 1 3 5 6
^
index = 0

Return:

0

--------------------------------------------------

Invariant Maintained Throughout:

If the target exists,
it is always within the search range [left, right].

Elements before 'left'
    < target

Elements after 'right'
    > target

When the loop terminates:

left > right

The target does not exist.

'left' points to the first position where the target can be inserted
while keeping the array sorted.

--------------------------------------------------

Time Complexity:
O(log n)

Space Complexity:
O(1)
*/