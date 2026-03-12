class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){

            // Skip duplicate i
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            for(int j = i + 1; j < n; j++){

                // Skip duplicate j
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while(left < right){

                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target){

                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        // Skip duplicate left
                        while(left < right && nums[left] == nums[left-1])
                            left++;

                        // Skip duplicate right
                        while(left < right && nums[right] == nums[right+1])
                            right--;
                    }

                    else if(sum > target){
                        right--;
                    }

                    else{
                        left++;
                    }
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
Fix the second element (j).

Step 4
Use two pointers to find the remaining two numbers.

left = j + 1
right = n - 1

Step 5
Compare sum with target.

sum == target → store quadruplet
sum > target  → move right--
sum < target  → move left++

Skip duplicates for i, j, left, right.

------------------------------------------------------------------

DRY RUN

Input

nums = [1,0,-1,0,-2,2]
target = 0

After sorting

[-2,-1,0,0,1,2]

------------------------------------------------------------------

Iteration 1

i = 0 → -2
j = 1 → -1

left = 2
right = 5

sum = -2 + -1 + 0 + 2 = -1

sum < target
left++

------------------------------------------------------------------

Now

i = 0
j = 1
left = 3
right = 5

sum = -2 + -1 + 0 + 2 = -1

left++

------------------------------------------------------------------

Now

i = 0
j = 1
left = 4
right = 5

sum = -2 + -1 + 1 + 2 = 0

Quadruplet Found

[-2,-1,1,2]

left++
right--

Loop ends

------------------------------------------------------------------

Iteration 2

i = 0 → -2
j = 2 → 0

left = 3
right = 5

sum = -2 + 0 + 0 + 2 = 0

Quadruplet Found

[-2,0,0,2]

left++
right--

------------------------------------------------------------------

Iteration 3

i = 1 → -1
j = 2 → 0

left = 3
right = 5

sum = -1 + 0 + 0 + 2 = 1

sum > target
right--

------------------------------------------------------------------

Now

left = 3
right = 4

sum = -1 + 0 + 0 + 1 = 0

Quadruplet Found

[-1,0,0,1]

------------------------------------------------------------------

Final Result

[-2,-1,1,2]
[-2,0,0,2]
[-1,0,0,1]

------------------------------------------------------------------

VISUALIZATION

Sorted Array

-2  -1   0   0   1   2

Step 1

i fixed

-2  -1   0   0   1   2
 i   j   L           R

Window shrinks

L →→→
←←← R

------------------------------------------------------------------

Step 2

i and j fixed

-2  -1   0   0   1   2
 i   j   L           R

Move pointers based on sum.

------------------------------------------------------------------

Step 3

Next pair

-2  -1   0   0   1   2
 i       j   L       R

Search remaining pairs.

------------------------------------------------------------------

MENTAL MODEL

Fix two numbers

nums[i] + nums[j] + nums[left] + nums[right] = target

Search remaining pair using two pointers.

------------------------------------------------------------------

Time Complexity

O(n³)

------------------------------------------------------------------

Space Complexity

O(1)
(excluding output)
*/