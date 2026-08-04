class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        // Traverse all remaining intervals.
        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

/*
APPROACH

Step 1

Sort all intervals according to
their starting point.

------------------------------------------------------------

Step 2

Insert the first interval into
the answer vector.

------------------------------------------------------------

Step 3

Traverse every remaining interval.

------------------------------------------------------------

Step 4

Compare the current interval with
the last merged interval.

If

Last End >= Current Start

↓

Intervals overlap.

Merge them by extending the end.

------------------------------------------------------------

Step 5

If there is no overlap,

simply push the current interval
into the answer.

------------------------------------------------------------

Example

Input

[[1,3],[2,6],[8,10],[15,18]]

------------------------------------------------------------

After Sorting

[[1,3],[2,6],[8,10],[15,18]]

------------------------------------------------------------

Initial

Answer

[1,3]

------------------------------------------------------------

Current Interval

[2,6]

Last Merged Interval

[1,3]

Visualization

[1-----3]
   [2--------6]

Since

3 >= 2

↓

Merge

Result

[1--------6]

Answer

[1,6]

------------------------------------------------------------

Current Interval

[8,10]

Last Merged Interval

[1,6]

Visualization

[1--------6]

          [8-----10]

Since

6 < 8

↓

No Overlap

Push

Answer

[1,6]

[8,10]

------------------------------------------------------------

Current Interval

[15,18]

Last Merged Interval

[8,10]

Visualization

[8-----10]

              [15------18]

Since

10 < 15

↓

No Overlap

Push

Answer

[1,6]

[8,10]

[15,18]

------------------------------------------------------------

VISUALIZATION

Original

[1---3]
     [2------6]

               [8---10]

                        [15---18]

------------------------------------------------------------

Merge

[1--------6]

               [8---10]

                        [15---18]

------------------------------------------------------------

Final Answer

[1--------6]

               [8---10]

                        [15---18]

------------------------------------------------------------

Another Example

Input

[[1,4],[4,5]]

Visualization

[1------4]
        [4------5]

Since

4 >= 4

↓

Merge

Result

[1-----------5]

------------------------------------------------------------

Invariant

Before processing every interval,

all intervals inside "ans"
are already merged and
non-overlapping.

Only the last merged interval
can overlap with the current one.

Hence,

Compare only

ans.back()

with

intervals[i]

------------------------------------------------------------

Why Sorting?

Without sorting

[8,10]

[1,3]

[2,6]

You cannot determine which
interval should be merged first.

Sorting guarantees that
possible overlaps can only occur
with the most recently merged interval.

------------------------------------------------------------

Time Complexity

Sorting

O(N log N)

Traversal

O(N)

Overall

O(N log N)

------------------------------------------------------------

Space Complexity

O(N)

(for the answer vector)
*/