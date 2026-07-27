// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        // Search space includes all versions from 1 to n.
        int l = 1;
        int r = n;

        // Continue searching until only one candidate remains.
        while (l < r) {

            // Calculate the middle version safely.
            int mid = l + (r - l) / 2;

            // If current version is bad,
            // the first bad version is either mid
            // or somewhere to its left.
            if (isBadVersion(mid))
                r = mid;

            // Otherwise,
            // all versions up to mid are good.
            // Search in the right half.
            else
                l = mid + 1;
        }

        // l and r converge to the first bad version.
        return l;
    }
};

/*
Dry Run Example:

n = 8

Versions:
1 2 3 4 5 6 7 8

Status:
G G G B B B B B

Legend:
G = Good Version
B = Bad Version

--------------------------------------------

Initial State

l = 1
r = 8

Search Space:

1 2 3 4 5 6 7 8
^             ^
l             r

--------------------------------------------

Step 1

mid = 1 + (8-1)/2
mid = 4

isBadVersion(4)

↓

true

Version 4 is bad.

The first bad version could still be 4,
so keep it in the search space.

r = mid

Search Space:

1 2 3 4
^     ^
l     r

--------------------------------------------

Step 2

mid = 1 + (4-1)/2
mid = 2

isBadVersion(2)

↓

false

Version 2 is good.

Discard versions 1 and 2.

l = mid + 1

Search Space:

3 4
^ ^
l r

--------------------------------------------

Step 3

mid = 3 + (4-3)/2
mid = 3

isBadVersion(3)

↓

false

Version 3 is good.

Discard version 3.

l = mid + 1

Search Space:

4
^
l,r

--------------------------------------------

Loop Ends

l = 4
r = 4

Only one version remains.

Return:

4

--------------------------------------------

Invariant Maintained Throughout

If isBadVersion(mid) == false

    All versions from 1 to mid
    are confirmed GOOD.

    Search the right half.

--------------------------------------------

If isBadVersion(mid) == true

    Current version is BAD.

    It could be the first bad version.

    Keep mid and search the left half.

--------------------------------------------

Why use r = mid instead of r = mid - 1?

Because mid itself may be the first bad version.

Removing it from the search could skip
the correct answer.

--------------------------------------------

Why use while(l < r)?

The search continues until both pointers
meet at a single version.

That remaining version is guaranteed to be
the first bad version.

--------------------------------------------

Time Complexity:

O(log n)

Space Complexity:

O(1)

--------------------------------------------

Pattern:

Binary Search on Answer
(Boundary Binary Search)

Goal:

Find the first position where a condition
changes from FALSE to TRUE.

FALSE FALSE FALSE TRUE TRUE TRUE
                   ^
            First TRUE
*/