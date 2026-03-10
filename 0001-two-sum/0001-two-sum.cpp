class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            // Check if complement already exists
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

/*
Approach 1 Explanation

Step 1
Iterate through the array.

Step 2
For every element calculate:

complement = target - nums[i]

Step 3
Check if complement exists in the hash map.

If yes → we found the pair.

Step 4
Otherwise store the current number and index in the map.

Time Complexity

Traversal      → O(n)
Hash lookup    → O(1)

Total          → O(n)

------------------------------------------------------------------------
APPROACH 2 BY USING TWO POINTERS
(Works only if array is sorted)
------------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum == target) {
                return {left, right};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};

---------------------
Dry Run Example

nums = [2,7,11,15]
target = 9

Hash Map = {}

--------------------------------------------------

Iteration 1

i = 0
nums[i] = 2

complement = 9 - 2 = 7

7 not in map

store

map = {2 : 0}

--------------------------------------------------

Iteration 2

i = 1
nums[i] = 7

complement = 9 - 7 = 2

2 found in map

return {0,1}

--------------------------------------------------

Output

[0,1]

--------------------------------------------------

Time Complexity

Hash Map Traversal

O(n)

Space Complexity

O(n)

--------------------------------------------------

Key Idea

target = a + b

so

b = target - a
*/