class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            // Skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int si = i + 1;
            int ei = n - 1;

            while (si < ei) {
                int sum = nums[i] + nums[si] + nums[ei];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[si++], nums[ei--]});
                    // Skip duplicate si
                    while (si < ei && nums[si] == nums[si - 1])
                        si++;
                    // Skip duplicate ei
                    while (si < ei && nums[ei] == nums[ei + 1])
                        ei--;
                } else if (sum > 0) {
                    ei--;
                } else {
                    si++;
                }
            }
        }
        return ans;
    }
};

/*
APPROACH

Step 1
Sort the array.

Step 2
Fix the first element (i).

Step 3
Use two pointers to find the other two numbers.

si = i + 1
ei = n - 1

Step 4
Move pointers based on the sum.

sum == 0 → store triplet
sum > 0  → move ei--
sum < 0  → move si++

Step 5
Skip duplicates for i, si, ei.

-------------------------------------------------------------------

DRY RUN WITH VISUALIZATION

Input

nums = [-1,0,1,2,-1,-4]

After sorting

[-4,-1,-1,0,1,2]

-------------------------------------------------------------------

Iteration 1

i = 0
nums[i] = -4

Array Visualization

-4  -1  -1   0   1   2
 i   si              ei

si = 1
ei = 5

sum = -4 + -1 + 2 = -3

sum < 0
move si++

-4  -1  -1   0   1   2
 i       si          ei

sum = -4 + -1 + 2 = -3

si++

-4  -1  -1   0   1   2
 i           si      ei

sum = -4 + 0 + 2 = -2

si++

-4  -1  -1   0   1   2
 i               si  ei

sum = -4 + 1 + 2 = -1

si++

Loop ends

-------------------------------------------------------------------

Iteration 2

i = 1
nums[i] = -1

Visualization

-4  -1  -1   0   1   2
     i   si          ei

sum = -1 + -1 + 2 = 0

Triplet Found

[-1,-1,2]

Move pointers

si++
ei--

Visualization

-4  -1  -1   0   1   2
     i       si      ei

sum = -1 + 0 + 1 = 0

Triplet Found

[-1,0,1]

Move pointers

si++
ei--

Loop ends

-------------------------------------------------------------------

Iteration 3

i = 2

nums[i] == nums[i-1]

Duplicate → skip

-------------------------------------------------------------------

Final Result

[-1,-1,2]
[-1,0,1]

-------------------------------------------------------------------

Time Complexity

O(n²)

-------------------------------------------------------------------

Space Complexity

O(1)
(excluding output)
*/