class Solution {
public:
    int mySqrt(int x) {

        // Search space:
        // Possible integer square roots lie between 0 and x.
        long l = 0;
        long r = x;

        // Binary Search
        while (l <= r) {

            // Calculate middle safely.
            long mid = l + (r - l) / 2;

            // Use long long to avoid integer overflow.
            long long square = 1LL * mid * mid;

            // Perfect square found.
            if (square == x)
                return mid;

            // Square is too large.
            // Search left half.
            if (square > x)
                r = mid - 1;

            // Square is too small.
            // Search right half.
            else
                l = mid + 1;
        }

        // r points to the largest integer
        // whose square is less than x.
        return r;
    }
};

/*
Problem:

Find the integer square root of x.

Return the largest integer k such that

k × k ≤ x

--------------------------------------------

Dry Run Example

Input:

x = 15

Search Space:

0 1 2 3 4 5 6 ...15

--------------------------------------------

Initial State

l = 0
r = 15

--------------------------------------------

Step 1

mid = 7

square = 49

49 > 15

Square is too large.

Search left.

r = 6

--------------------------------------------

Step 2

l = 0
r = 6

mid = 3

square = 9

9 < 15

Square is too small.

Search right.

l = 4

--------------------------------------------

Step 3

l = 4
r = 6

mid = 5

square = 25

25 > 15

Search left.

r = 4

--------------------------------------------

Step 4

l = 4
r = 4

mid = 4

square = 16

16 > 15

Search left.

r = 3

--------------------------------------------

Loop Ends

l = 4
r = 3

Return r

Answer = 3

Because:

3² = 9 ≤ 15

4² = 16 > 15

--------------------------------------------

Invariant Maintained

If mid² > x

The answer lies to the left.

Discard right half.

--------------------------------------------

If mid² < x

mid is a possible answer.

There may be a larger valid square root.

Search right half.

--------------------------------------------

Why return r?

When the loop terminates,

l becomes the first value whose square
is greater than x.

r becomes the largest value whose square
is less than or equal to x.

--------------------------------------------

Time Complexity:

O(log x)

Space Complexity:

O(1)

--------------------------------------------

Pattern:

Binary Search on Answer

Goal:

Find the largest value satisfying

mid² ≤ x
*/