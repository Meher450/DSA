class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {

            string word = "";

            // Step 2: Extract characters until space
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Step 3: Reverse the extracted word
            reverse(word.begin(), word.end());

            // Step 4: Add the word to answer if not empty
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        // Step 5: Remove the first extra space
        return ans.substr(1);
    }
};

/*
Goal:
Reverse the order of words in a string.

Example:
s = "the sky is blue"

Output:
"blue is sky the"

Important Conditions:
1) Remove extra spaces
2) Words should appear in reversed order
3) Only one space between words

--------------------------------------------------

Core Idea (Approach):

Instead of directly reversing words,
the algorithm uses a trick:

1) Reverse the whole string
2) Extract words one by one
3) Reverse each extracted word
4) Append it to the result

--------------------------------------------------

Step 1: Reverse Entire String

reverse(s.begin(), s.end())

Example:

Original:
"the sky is blue"

After reverse:
"eulb si yks eht"

--------------------------------------------------

Step 2: Extract Words

Traverse the reversed string.

Characters are collected until a space appears.

Example:

Current string:
"eulb si yks eht"

First word extracted:
"eulb"

--------------------------------------------------

Step 3: Reverse Each Word

reverse(word.begin(), word.end())

"eulb" → "blue"

--------------------------------------------------

Step 4: Add Word to Result

ans += " " + word

We add a space before each word.

Example progression:

ans = " blue"
ans = " blue is"
ans = " blue is sky"
ans = " blue is sky the"

--------------------------------------------------

Step 5: Remove First Space

Since the result starts with a space,
we remove it using:

ans.substr(1)

Final result:
"blue is sky the"

--------------------------------------------------

Dry Run Example:

s = "the sky is blue"

--------------------------------------------------
Step 1: Reverse String

s = "eulb si yks eht"

--------------------------------------------------
Step 2: Extract Words

Word 1:
"eulb" → reverse → "blue"

ans = " blue"

--------------------------------------------------
Word 2:
"si" → reverse → "is"

ans = " blue is"

--------------------------------------------------
Word 3:
"yks" → reverse → "sky"

ans = " blue is sky"

--------------------------------------------------
Word 4:
"eht" → reverse → "the"

ans = " blue is sky the"

--------------------------------------------------

Step 3: Remove first space

ans.substr(1)

Result:
"blue is sky the"

--------------------------------------------------

Final Output:

"blue is sky the"

--------------------------------------------------

Time Complexity:

O(n)

Each character is processed a constant number of times.

--------------------------------------------------

Space Complexity:

O(n)

Because a new string "ans" is created.
*/