class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

/*
Dry Run Example:

s = "daabcbaabcbc"
part = "abc"

--------------------------------------------------
Initial State:

s = daabcbaabcbc

--------------------------------------------------
Step 1:

s.find("abc") = 2

Erase substring starting at index 2 of length 3

Removed: "abc"

New String:
s = "dabaabcbc"

--------------------------------------------------
Step 2:

s.find("abc") = 4

Erase substring starting at index 4

Removed: "abc"

New String:
s = "dababc"

--------------------------------------------------
Step 3:

s.find("abc") = 3

Erase substring starting at index 3

Removed: "abc"

New String:
s = "dab"

--------------------------------------------------
Step 4:

s.find("abc") = npos
(meaning substring not found)

Condition fails:
npos < s.length() → false

Loop stops.

--------------------------------------------------
Final State:

s = "dab"

--------------------------------------------------
Final Output:

"dab"

*/