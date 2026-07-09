class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = 0;
        int left = 0;
        // Calculate total sum
        for(int num : nums) total += num;
        // Traverse the array
        for(int i = 0; i < nums.size(); i++){
            int right = total - nums[i] - left;
            if(left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};

/*
APPROACH

Step 1

Find the total sum of the array.

Step 2

Maintain a running left sum.

Step 3

For every index,

rightSum = totalSum - currentElement - leftSum

Step 4

If

leftSum == rightSum

then current index is the middle index.

Step 5

Otherwise, add the current element to leftSum
and continue.

---------------------------------------------------------------------

DRY RUN

nums = [2,3,-1,8,4]

---------------------------------------------------------------------

Calculate Total Sum

total = 2 + 3 + (-1) + 8 + 4

total = 16

left = 0

---------------------------------------------------------------------

Iteration 1

i = 0

nums[i] = 2

right = 16 - 2 - 0 = 14

left = 0

0 != 14

Update

left = 2

---------------------------------------------------------------------

Iteration 2

i = 1

nums[i] = 3

right = 16 - 3 - 2 = 11

left = 2

2 != 11

Update

left = 5

---------------------------------------------------------------------

Iteration 3

i = 2

nums[i] = -1

right = 16 - (-1) - 5 = 12

left = 5

5 != 12

Update

left = 4

---------------------------------------------------------------------

Iteration 4

i = 3

nums[i] = 8

right = 16 - 8 - 4 = 4

left = 4

left == right

Return 3

---------------------------------------------------------------------

FINAL RESULT

3

---------------------------------------------------------------------

VISUALIZATION

nums

[2   3   -1   8   4]

Iteration 1

[] | 2 | [3  -1  8  4]

left = 0

right = 14

---------------------------------------------------------------------

Iteration 2

[2] | 3 | [-1  8  4]

left = 2

right = 11

---------------------------------------------------------------------

Iteration 3

[2  3] | -1 | [8  4]

left = 5

right = 12

---------------------------------------------------------------------

Iteration 4

[2  3  -1] | 8 | [4]

left = 4

right = 4

✔ Middle Index Found

---------------------------------------------------------------------

Time Complexity

O(n)

---------------------------------------------------------------------

Space Complexity

O(1)

---------------------------------------------------------------------

Key Idea

For every index,

leftSum = sum of elements before current index

rightSum = totalSum - currentElement - leftSum

If

leftSum == rightSum

Return the current index.
*/