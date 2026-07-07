class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];     // first half
            ans[i + n] = nums[i]; // second half
        }
        return ans;
    }
};

/*
APPROACH

Step 1
Create a new array of size 2*n.

Step 2
Copy original array into first half.

Step 3
Copy again into second half.

ans[i]     = nums[i]
ans[i + n] = nums[i]

---------------------------------------------------------------------

DRY RUN

nums = [1,2,1]

n = 3

Initialize

ans = [_, _, _, _, _, _]

---------------------------------------------------------------------

Iteration 1

i = 0

ans[0] = 1
ans[3] = 1

ans = [1, _, _, 1, _, _]

---------------------------------------------------------------------

Iteration 2

i = 1

ans[1] = 2
ans[4] = 2

ans = [1, 2, _, 1, 2, _]

---------------------------------------------------------------------

Iteration 3

i = 2

ans[2] = 1
ans[5] = 1

ans = [1, 2, 1, 1, 2, 1]

---------------------------------------------------------------------

FINAL RESULT

[1, 2, 1, 1, 2, 1]

---------------------------------------------------------------------

VISUALIZATION

nums

[1   2   1]

Concatenation

[1   2   1 | 1   2   1]

         first   second
         half    half

---------------------------------------------------------------------

Time Complexity

O(n)

---------------------------------------------------------------------

Space Complexity

O(n)

---------------------------------------------------------------------

Key Idea

Duplicate the array by placing it twice:

ans = nums + nums
*/