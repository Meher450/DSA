class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int counter = 0;
        int mid = n / 2;
        for (int i = 0; i < n; i++) {
            counter += abs(nums[i] - nums[mid]);
        }
        return counter;
    }
};

/*
APPROACH:
1. Sort the array in ascending order.
2. Find the median using nums[n / 2].
3. The median minimizes the total absolute difference
   between all elements and the target value.
4. Calculate the moves required for each element using
   abs(nums[i] - nums[mid]).
5. Add all the differences to counter and return the total.

DRY RUN:
Input: nums = [1, 2, 9, 10, 12]

After sorting: [1, 2, 9, 10, 12]
Median = nums[5 / 2] = nums[2] = 9

Element     Moves             Total
1           abs(1 - 9) = 8      8
2           abs(2 - 9) = 7     15
9           abs(9 - 9) = 0     15
10          abs(10 - 9) = 1    16
12          abs(12 - 9) = 3    19

Output: 19

COMPLEXITY:
Time: O(n log n) - sorting the array takes O(n log n),
      followed by a linear traversal in O(n).
Space: O(1) auxiliary space, excluding sorting implementation details.

PATTERN:
Sorting + Greedy + Median
*/
