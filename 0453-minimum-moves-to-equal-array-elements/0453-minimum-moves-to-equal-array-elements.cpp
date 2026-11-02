class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int counter = 0;
        int mid = *min_element(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            counter += abs(nums[i] - mid);
        }

        return counter;
    }
};

/*
APPROACH:
1. Find the minimum element using min_element().
2. Treat the minimum element as the target value.
3. For each element, calculate the difference between
   that element and the minimum using abs().
4. Add all differences to counter.
5. Return counter as the minimum number of moves.

WHY THIS WORKS:
Incrementing n - 1 elements by 1 is equivalent, in terms
of relative differences, to decrementing the remaining
element by 1.

Therefore, we can imagine decreasing each element until
all elements equal the minimum element.

Since every element is greater than or equal to the minimum,
abs() is unnecessary, but it gives the same result here.

DRY RUN:
Input: nums = [1, 2, 3]

Minimum = 1

Element     Calculation       Total
1           abs(1 - 1) = 0      0
2           abs(2 - 1) = 1      1
3           abs(3 - 1) = 2      3

Output: 3

COMPLEXITY:
Time: O(n) - finding the minimum takes O(n), and
      traversing the array takes O(n).
Space: O(1) auxiliary space.

PATTERN:
Greedy + Mathematical Transformation
*/
