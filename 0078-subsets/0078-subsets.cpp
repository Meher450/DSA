class Solution {
public:

    void backtrack(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        // store current subset
        ans.push_back(curr);
        for(int i = index; i < nums.size(); i++){
            // choose element
            curr.push_back(nums[i]);
            // explore further
            backtrack(i + 1, nums, curr, ans);
            // backtrack (remove last element)
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }
};

/*
APPROACH

Step 1
Start with an empty subset.

Step 2
At every position we have two choices

Include the element
Skip the element

Step 3
Use recursion to explore all possibilities.

Step 4
Backtrack by removing the last element and trying the next option.

---------------------------------------------------------------------

DRY RUN

nums = [1,2,3]

Start

curr = []

store → []

---------------------------------------------------------------------

Choose 1

curr = [1]

store → [1]

---------------------------------------------------------------------

Choose 2

curr = [1,2]

store → [1,2]

---------------------------------------------------------------------

Choose 3

curr = [1,2,3]

store → [1,2,3]

Backtrack

curr = [1,2]

---------------------------------------------------------------------

Skip 3

Backtrack

curr = [1]

---------------------------------------------------------------------

Choose 3

curr = [1,3]

store → [1,3]

Backtrack

curr = [1]

---------------------------------------------------------------------

Backtrack

curr = []

---------------------------------------------------------------------

Choose 2

curr = [2]

store → [2]

---------------------------------------------------------------------

Choose 3

curr = [2,3]

store → [2,3]

Backtrack

curr = [2]

---------------------------------------------------------------------

Backtrack

curr = []

---------------------------------------------------------------------

Choose 3

curr = [3]

store → [3]

---------------------------------------------------------------------

FINAL RESULT

[]
[1]
[1,2]
[1,2,3]
[1,3]
[2]
[2,3]
[3]

---------------------------------------------------------------------

VISUALIZATION (RECURSION TREE)

                    []
               /      |      \
             [1]     [2]     [3]
           /     \      \
       [1,2]   [1,3]    [2,3]
        |
     [1,2,3]

Every node in the tree is a subset.

---------------------------------------------------------------------

Total Subsets

2^n

Example

n = 3

Total = 8 subsets

---------------------------------------------------------------------

Time Complexity

O(n * 2^n)

---------------------------------------------------------------------

Space Complexity

O(n)
(recursion stack)
*/