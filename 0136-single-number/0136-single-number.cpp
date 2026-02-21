class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        
        // Traverse through the array
        for (int i = 0; i < n; i++) {
            
            // XOR current element with answer
            // Properties of XOR:
            // 1) a ^ a = 0
            // 2) a ^ 0 = a
            // 3) XOR is commutative and associative
            
            answer ^= nums[i];
        }
        
        // After XOR-ing all elements,
        // duplicate numbers cancel out
        // Only the single occurring number remains
        return answer;
    }
};


/*
=================================
DRY RUN (After Code Execution)
=================================

Example Input:
nums = [4, 1, 2, 1, 2]

Initial:
answer = 0

i = 0
answer = 0 ^ 4 = 4

i = 1
answer = 4 ^ 1 = 5

i = 2
answer = 5 ^ 2 = 7

i = 3
answer = 7 ^ 1 = 6

i = 4
answer = 6 ^ 2 = 4


Final Result:
answer = 4


---------------------------------

Why This Works:

Given array:
[4, 1, 2, 1, 2]

Rearranging using XOR properties:

4 ^ 1 ^ 2 ^ 1 ^ 2
= 4 ^ (1 ^ 1) ^ (2 ^ 2)
= 4 ^ 0 ^ 0
= 4

Duplicates cancel out.
Only the element appearing once remains.

---------------------------------

Another Example:
nums = [2, 2, 3]

answer = 0

0 ^ 2 = 2
2 ^ 2 = 0
0 ^ 3 = 3

Final answer = 3
*/