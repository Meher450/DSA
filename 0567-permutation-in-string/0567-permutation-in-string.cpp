class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2)
            return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2)
            return true;

        int j = 0;
        for (int i = n1; i < n2; i++) {
            count2[s2[i] - 'a']++;
            count2[s2[j] - 'a']--;
            if (count1 == count2)
                return true;
            j++;
        }
        return false;
    }
};

/*
Dry Run Example:

s1 = "ab"
s2 = "eidbaooo"

n1 = 2
n2 = 8

--------------------------------------------------
Initial Window (size 2):

Window = "ei"

count1 (s1="ab"):
a:1
b:1

count2 ("ei"):
e:1
i:1

Not equal.

--------------------------------------------------
Slide Window

Step 1:

Remove 'e'
Add 'd'

Window = "id"

count2:
i:1
d:1

Not equal.

--------------------------------------------------
Step 2:

Remove 'i'
Add 'b'

Window = "db"

count2:
d:1
b:1

Not equal.

--------------------------------------------------
Step 3:

Remove 'd'
Add 'a'

Window = "ba"

count2:
b:1
a:1

Now:

count1:
a:1
b:1

count2:
a:1
b:1

Arrays match.

Return true.

--------------------------------------------------

Final Result:

Permutation "ba" exists in s2.

Output:
true

--------------------------------------------------

Sliding Window Invariant:

Window size = n1 (always constant)

At each step:
1 character enters the window
1 character leaves the window

This keeps the window size fixed while scanning the string.

--------------------------------------------------

Time Complexity:

O(26 * n2)
≈ O(n)

(26 comparison is constant)

--------------------------------------------------

Space Complexity:

O(26) → constant space
*/