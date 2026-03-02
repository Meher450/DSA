class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // last valid element in nums1
        int j = n - 1;       // last element in nums2
        int idx = m + n - 1; // last index of nums1 (final position)

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }
};

/*
Dry Run Example:

nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3

Initial:
i = 2 (value 3)
j = 2 (value 6)
idx = 5

----------------------------------------------------
State:
nums1 = [1, 2, 3, 0, 0, 0]

Valid nums1 area: [1 2 3]
nums2:            [2 5 6]
Write position:              idx=5

----------------------------------------------------
Step 1:
Compare nums1[i]=3 and nums2[j]=6
6 is bigger → place 6 at idx

nums1 = [1, 2, 3, 0, 0, 6]

i=2, j=1, idx=4

----------------------------------------------------
Step 2:
Compare nums1[i]=3 and nums2[j]=5
5 is bigger → place 5

nums1 = [1, 2, 3, 0, 5, 6]

i=2, j=0, idx=3

----------------------------------------------------
Step 3:
Compare nums1[i]=3 and nums2[j]=2
3 is bigger → place 3

nums1 = [1, 2, 3, 3, 5, 6]

i=1, j=0, idx=2

----------------------------------------------------
Step 4:
Compare nums1[i]=2 and nums2[j]=2
2 (nums2) is chosen (else case)

nums1 = [1, 2, 2, 3, 5, 6]

i=1, j=-1, idx=1

----------------------------------------------------
Main loop stops because j < 0

Now check remaining nums2 elements:
j = -1 → none left

Remaining nums1 elements are already correct.

----------------------------------------------------
Final Answer:
[1, 2, 2, 3, 5, 6]

----------------------------------------------------

Visual Understanding:

We always fill from the BACK.

Initial:
[1 2 3 | 0 0 0]
         ↑ write from here

After full merge:
[1 2 2 3 5 6]

Time Complexity: O(m + n)
Space Complexity: O(1)
*/