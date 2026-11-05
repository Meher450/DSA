class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int counter = 0;

        for (int i = 0; i < arr1.size(); i++) {
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i] - d);

            if (it == arr2.end() || *it > arr1[i] + d) {
                counter++;
            }
        }

        return counter;
    }
};

/*
APPROACH:
1. Sort arr2 in ascending order to enable binary search.
2. Traverse each element of arr1.
3. For the current element x, calculate the invalid range:
      [x - d, x + d]
4. Use lower_bound() to find the first element in arr2
   that is greater than or equal to x - d.
5. Check the following conditions:
   - If the iterator reaches arr2.end(), no element exists
     at or above x - d.
   - If the found element is greater than x + d,
     no element exists inside the invalid range.
6. If either condition is true, the current element satisfies
   the distance requirement. Increment counter.
7. Return counter.

WHY THIS WORKS:
An element x from arr1 is valid only if every element y
from arr2 satisfies:

      abs(x - y) > d

This is equivalent to saying that no element of arr2
exists in the range:

      [x - d, x + d]

Since arr2 is sorted, lower_bound() efficiently finds
the first possible element in this range.

DRY RUN:
Input:
arr1 = [4, 5, 8]
arr2 = [10, 9, 1, 8]
d = 2

After sorting arr2:
[1, 8, 9, 10]

For x = 4:
Invalid range = [2, 6]
lower_bound(2) gives 8.
8 > 6, so valid.
counter = 1

For x = 5:
Invalid range = [3, 7]
lower_bound(3) gives 8.
8 > 7, so valid.
counter = 2

For x = 8:
Invalid range = [6, 10]
lower_bound(6) gives 8.
8 is within [6, 10], so invalid.
counter = 2

Output: 2

COMPLEXITY:
Time:
- Sorting arr2: O(m log m)
- Traversing arr1: O(n)
- Binary search for each element: O(n log m)
- Overall: O(m log m + n log m)

Space:
- O(1) auxiliary space, excluding sorting implementation details.

PATTERN:
Sorting + Binary Search + STL (lower_bound)
*/