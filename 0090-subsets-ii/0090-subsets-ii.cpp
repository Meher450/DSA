class Solution {
public:
    void backtrack(int index, vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i = index; i < nums.size(); i++){
            // skip duplicates
            if(i > index && nums[i] == nums[i-1])
                continue;
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }
};

/*
APPROACH

Step 1
Sort the array to group duplicates.

Step 2
Generate subsets using backtracking.

Step 3
Skip duplicates when:

nums[i] == nums[i-1]
and i > index

---------------------------------------------------------------------

DRY RUN

nums = [1,2,2]

Sorted

[1,2,2]

Start

[]

---------------------------------------------------------------------

Choose 1

[1]

Choose 2

[1,2]

Choose 2

[1,2,2]

Backtrack

[1]

Skip duplicate 2

---------------------------------------------------------------------

Backtrack

[]

Choose 2

[2]

Choose next 2

[2,2]

---------------------------------------------------------------------

FINAL RESULT

[]
[1]
[1,2]
[1,2,2]
[2]
[2,2]

---------------------------------------------------------------------

Time Complexity

O(n * 2^n)

---------------------------------------------------------------------

Space Complexity

O(n)

---------------------------------------------------------------------

Key Insight

Sort array + Skip duplicates during recursion
*/