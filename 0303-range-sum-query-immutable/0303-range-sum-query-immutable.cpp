class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        prefix[0] = nums[0];
        // Build Prefix Sum Array
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // If range starts from index 0
        if(left == 0)   return prefix[right];
        // Sum of range = Prefix[right] - Prefix[left-1]
        return prefix[right] - prefix[left-1];
    }
};

/*
Your NumArray object will be instantiated and called as such:

NumArray* obj = new NumArray(nums);
int ans = obj->sumRange(left, right);

---------------------------------------------------------------------

APPROACH

Step 1

Construct a Prefix Sum Array.

prefix[i] = sum of elements from index 0 to i.

Step 2

To find the sum of any range [left, right]:

If left == 0

Answer = prefix[right]

Otherwise

Answer = prefix[right] - prefix[left-1]

---------------------------------------------------------------------

PREFIX SUM FORMULA

prefix[i] = prefix[i-1] + nums[i]

Range Sum

sum(left, right)

=

prefix[right] - prefix[left-1]

---------------------------------------------------------------------

DRY RUN

nums = [-2,0,3,-5,2,-1]

---------------------------------------------------------------------

Build Prefix Array

Index

0   1   2   3   4   5

nums

-2   0   3  -5   2  -1

prefix

-2  -2   1  -4  -2  -3

---------------------------------------------------------------------

Query 1

left = 0

right = 2

Since left == 0

Answer

prefix[2]

=

1

Subarray

[-2,0,3]

Sum = 1

---------------------------------------------------------------------

Query 2

left = 2

right = 5

Answer

prefix[5] - prefix[1]

=

-3 - (-2)

=

-1

Subarray

[3,-5,2,-1]

Sum = -1

---------------------------------------------------------------------

VISUALIZATION

nums

[-2   0   3   -5   2   -1]

Prefix

[-2  -2   1   -4  -2  -3]

---------------------------------------------------------------------

Range

left = 2

right = 5

nums

-2   0 | 3   -5   2   -1
        <------------->

Use Prefix

prefix[5]

minus

prefix[1]

↓

-3 - (-2)

↓

-1

---------------------------------------------------------------------

Another Example

left = 1

right = 4

nums

-2 | 0   3   -5   2 | -1
     <------------>

Answer

prefix[4] - prefix[0]

=

-2 - (-2)

=

0

---------------------------------------------------------------------

Time Complexity

Constructor

O(n)

sumRange()

O(1)

---------------------------------------------------------------------

Space Complexity

O(n)

---------------------------------------------------------------------

Key Idea

Store cumulative sums in a Prefix Sum Array.

Instead of calculating every range repeatedly,

Range Sum

=

prefix[right] - prefix[left-1]

This answers every query in O(1).
*/