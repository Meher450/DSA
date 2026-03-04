class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int idx = 0; // position where we write compressed characters

        for (int i = 0; i < n; i++) {

            char ch = chars[i];
            int count = 0;

            // Count how many times the current character repeats
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Write the character
            if (count == 1) {
                chars[idx++] = ch;
            } else {
                chars[idx++] = ch;

                // Convert count into digits and store them
                string str = to_string(count);

                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--; // step back because for-loop will increment i
        }

        // Resize vector to compressed size
        chars.resize(idx);

        return idx;
    }
};

/*
Goal:
Compress the character array using Run-Length Encoding.

Rules:
1) Consecutive repeating characters are replaced with:
      character + count
2) If count = 1, only the character is stored.
3) Compression must be done IN-PLACE in the same vector.

Example:
chars = ["a","a","b","b","c","c","c"]

Output vector becomes:
["a","2","b","2","c","3"]

Return length = 6

--------------------------------------------------

Core Idea (Approach):

The algorithm scans the array and counts
how many times each character repeats consecutively.

Steps:
1) Pick a character
2) Count how many times it repeats
3) Write the character
4) If count > 1 → write digits of count
5) Continue with next character group

--------------------------------------------------

Important Variables

n
→ size of original array

idx
→ position where compressed characters are written

i
→ scans the original array

count
→ number of repetitions of a character

--------------------------------------------------

Step 1: Traverse the Array

for (int i = 0; i < n; i++)

We process one group of identical characters at a time.

--------------------------------------------------

Step 2: Count Consecutive Characters

while (i < n && chars[i] == ch)
{
    count++;
    i++;
}

Example:

chars = a a b b c c c

For 'a'

count = 2

--------------------------------------------------

Step 3: Write Character

chars[idx++] = ch

Example:

a a → write 'a'

--------------------------------------------------

Step 4: Write Count (if >1)

If count > 1:

Convert count into string.

Example:

count = 12

string = "12"

Then insert each digit separately.

Example:

chars[idx++] = '1'
chars[idx++] = '2'

--------------------------------------------------

Step 5: i--

The inner while loop moves i forward
past the repeated characters.

But the for-loop will also increase i.

So we move back one step.

Example:

while loop stops at first different char.

i--

So the for loop continues correctly.

--------------------------------------------------

Dry Run Example:

chars = ["a","a","b","b","c","c","c"]

--------------------------------------------------
Initial State

i = 0
idx = 0

[a a b b c c c]

--------------------------------------------------
Step 1: Character = 'a'

count occurrences

a a

count = 2

Write:

chars[0] = 'a'
chars[1] = '2'

idx = 2

--------------------------------------------------
Step 2: Character = 'b'

b b

count = 2

Write:

chars[2] = 'b'
chars[3] = '2'

idx = 4

--------------------------------------------------
Step 3: Character = 'c'

c c c

count = 3

Write:

chars[4] = 'c'
chars[5] = '3'

idx = 6

--------------------------------------------------

Compressed Array

[a 2 b 2 c 3]

--------------------------------------------------

Resize Vector

chars.resize(6)

--------------------------------------------------

Final Output

["a","2","b","2","c","3"]

Return value:

6

--------------------------------------------------

Visualization

Original:
[a a b b c c c]

Compressed writing process:

[a 2 b 2 c 3 _]

Final resized array:

[a 2 b 2 c 3]

--------------------------------------------------

Time Complexity:

O(n)

Each character is visited once.

--------------------------------------------------

Space Complexity:

O(1)

Compression is done in-place.
*/