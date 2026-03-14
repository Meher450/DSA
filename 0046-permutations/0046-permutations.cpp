class Solution {
public:
    void generate(int idx, vector<int>& nums, vector<vector<int>>& ans){
        // base case
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            generate(idx + 1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(0, nums, ans);
        return ans;
    }
};

/*
APPROACH

Step 1
Fix one position at a time.

Step 2
Swap the current index with every element after it.

Step 3
Recursively generate permutations for the remaining array.

Step 4
Backtrack by swapping back.

---------------------------------------------------------------------

DRY RUN

nums = [1,2,3]

Start

idx = 0

---------------------------------------------------------------------

Swap 0 with 0

[1,2,3]

idx = 1

Swap 1 with 1

[1,2,3]

idx = 2

Swap 2 with 2

[1,2,3]

Permutation found

[1,2,3]

---------------------------------------------------------------------

Swap 1 with 2

[1,3,2]

Permutation found

[1,3,2]

---------------------------------------------------------------------

Swap 0 with 1

[2,1,3]

Permutation found

[2,1,3]

Next

[2,3,1]

---------------------------------------------------------------------

Swap 0 with 2

[3,2,1]

Permutation found

[3,2,1]

Next

[3,1,2]

---------------------------------------------------------------------

FINAL RESULT

[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,2,1]
[3,1,2]

---------------------------------------------------------------------

VISUALIZATION (RECURSION TREE)

                [1,2,3]
           /        |        \
      [1,2,3]   [2,1,3]   [3,2,1]
       /   \       /   \       /   \
  [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]

Each level fixes one position.

---------------------------------------------------------------------

Time Complexity

O(n * n!)

---------------------------------------------------------------------

Space Complexity

O(n)
(recursion stack)
*/