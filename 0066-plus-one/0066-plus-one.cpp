class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;  // Current digit is 9, make it 0
        }
        digits.insert(digits.begin(), 1);  // All digits were 9
        return digits;
    }
};

/*
APPROACH

Step 1

Start traversing from the last digit.

Step 2

If the current digit is not 9,
increment it and return.

Step 3

If the current digit is 9,
change it to 0 and continue moving left.

Step 4

If all digits are 9,
insert 1 at the beginning.

---------------------------------------------------------------------

DRY RUN 1

digits = [1,2,3]

n = 3

---------------------------------------------------------------------

Iteration 1

i = 2

digits[2] = 3

3 != 9

Increment

digits = [1,2,4]

Return

---------------------------------------------------------------------

FINAL RESULT

[1,2,4]

=====================================================================

DRY RUN 2

digits = [4,3,9]

---------------------------------------------------------------------

Iteration 1

i = 2

digits[2] = 9

Make it 0

digits = [4,3,0]

---------------------------------------------------------------------

Iteration 2

i = 1

digits[1] = 3

3 != 9

Increment

digits = [4,4,0]

Return

---------------------------------------------------------------------

FINAL RESULT

[4,4,0]

=====================================================================

DRY RUN 3

digits = [9,9,9]

---------------------------------------------------------------------

Iteration 1

i = 2

digits = [9,9,0]

---------------------------------------------------------------------

Iteration 2

i = 1

digits = [9,0,0]

---------------------------------------------------------------------

Iteration 3

i = 0

digits = [0,0,0]

Loop Ends

Insert 1 at beginning

digits = [1,0,0,0]

---------------------------------------------------------------------

FINAL RESULT

[1,0,0,0]

---------------------------------------------------------------------

VISUALIZATION

Example 1

[1 2 3]

      ↑

Increment last digit

↓

[1 2 4]

---------------------------------------------------------------------

Example 2

[4 3 9]

      ↑

9 becomes 0

↓

[4 3 0]

   ↑

Increment previous digit

↓

[4 4 0]

---------------------------------------------------------------------

Example 3

[9 9 9]

      ↑

[9 9 0]

   ↑

[9 0 0]

↑

[0 0 0]

Insert 1

↓

[1 0 0 0]

---------------------------------------------------------------------

Time Complexity

O(n)

---------------------------------------------------------------------

Space Complexity

O(1)

(Except when all digits are 9, where one extra element is inserted.)

---------------------------------------------------------------------

Key Idea

Traverse from right to left.

If digit != 9

Increment and return.

Else

Make it 0 and continue.

If all digits are 9

Insert 1 at the beginning.
*/
