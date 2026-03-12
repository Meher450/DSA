class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        // prefixSum = 0 appears once
        mp[0] = 1;

        int currSum = 0;
        int count = 0;

        for(int num : nums){

            currSum += num;

            // check if (currSum - k) appeared before
            if(mp.find(currSum - k) != mp.end()){
                count += mp[currSum - k];
            }

            // store current prefix sum
            mp[currSum]++;
        }

        return count;
    }
};

/*
Approach Explanation

Step 1
Maintain a running prefix sum.

currSum = sum of elements from index 0 → current index.

Step 2
If a subarray sum equals k then

prefixSum[j] - prefixSum[i] = k

Rearrange

prefixSum[i] = prefixSum[j] - k

So if (currSum - k) already exists in hashmap,
then a valid subarray exists.

Step 3
Store frequency of prefix sums in hashmap.

------------------------------------------------------------------

Dry Run Example

nums = [1,2,3]
k = 3

Initialize

currSum = 0
count = 0
map = {0:1}

------------------------------------------------------------------

Iteration 1

num = 1

currSum = 1

currSum - k = 1 - 3 = -2

not in map

map = {0:1, 1:1}

------------------------------------------------------------------

Iteration 2

num = 2

currSum = 3

currSum - k = 3 - 3 = 0

0 exists in map

count += map[0]

count = 1

map = {0:1, 1:1, 3:1}

------------------------------------------------------------------

Iteration 3

num = 3

currSum = 6

currSum - k = 6 - 3 = 3

3 exists in map

count += map[3]

count = 2

map = {0:1, 1:1, 3:1, 6:1}

------------------------------------------------------------------

Visualization

Prefix Sum Movement

1 → 3 → 6

Check each step

currSum - k

Step 1

1 - 3 = -2  (not found)

Step 2

3 - 3 = 0   (found)

Subarray

[1,2]

Step 3

6 - 3 = 3   (found)

Subarray

[3]

------------------------------------------------------------------

Total Subarrays

2

------------------------------------------------------------------

Time Complexity

O(n)

------------------------------------------------------------------

Space Complexity

O(n)

------------------------------------------------------------------

Key Idea

Subarray Sum

prefixSum[j] - prefixSum[i] = k
*/
