class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            // Check if current number appeared before
            if(mp.find(nums[i]) != mp.end()){
                // Check index difference
                if(i - mp[nums[i]] <= k)  return true;
            }
            // Store latest index of current number
            mp[nums[i]] = i;
        }
        return false;
    }
};

/*
APPROACH

Step 1

Use a HashMap to store

Value → Latest Index

Step 2

Traverse the array.

Step 3

If the current value already exists,

calculate the index difference.

distance = currentIndex - previousIndex

Step 4

If

distance <= k

Return true.

Step 5

Otherwise,

update the latest index of the current value.

---------------------------------------------------------------------

DRY RUN

nums = [1,2,3,1]

k = 3

---------------------------------------------------------------------

Initialize

HashMap = { }

---------------------------------------------------------------------

Iteration 1

i = 0

nums[i] = 1

1 not found

Store

1 → 0

HashMap

{1 : 0}

---------------------------------------------------------------------

Iteration 2

i = 1

nums[i] = 2

2 not found

Store

2 → 1

HashMap

{1 : 0, 2 : 1}

---------------------------------------------------------------------

Iteration 3

i = 2

nums[i] = 3

3 not found

Store

3 → 2

HashMap

{1 : 0, 2 : 1, 3 : 2}

---------------------------------------------------------------------

Iteration 4

i = 3

nums[i] = 1

1 found

Previous Index = 0

Distance

3 - 0 = 3

3 <= 3

Return true

---------------------------------------------------------------------

FINAL RESULT

true

=====================================================================

DRY RUN 2

nums = [1,2,3,1,2,3]

k = 2

---------------------------------------------------------------------

Iteration 4

Current = 1

Previous Index = 0

Distance

3 - 0 = 3

3 > 2

Update

1 → 3

---------------------------------------------------------------------

Iteration 5

Current = 2

Previous Index = 1

Distance

4 - 1 = 3

3 > 2

Update

2 → 4

---------------------------------------------------------------------

Iteration 6

Current = 3

Previous Index = 2

Distance

5 - 2 = 3

3 > 2

Update

3 → 5

Loop Ends

Return false

---------------------------------------------------------------------

VISUALIZATION

Example 1

nums

[1   2   3   1]

Index

 0   1   2   3

HashMap

1 → 0

↓

Current Index = 3

Distance

3 - 0 = 3

≤ k

✔ Duplicate Found

---------------------------------------------------------------------

Example 2

nums

[1   2   3   1   2   3]

Index

 0   1   2   3   4   5

Distance

1

↓

3

3 > k

Update latest index

Continue searching

---------------------------------------------------------------------

Time Complexity

O(n)

---------------------------------------------------------------------

Space Complexity

O(n)

---------------------------------------------------------------------

Key Idea

HashMap stores

Value → Latest Index

For every duplicate value,

Distance = Current Index - Previous Index

If

Distance <= k

Return true.

Otherwise,

Update the latest index and continue.
*/