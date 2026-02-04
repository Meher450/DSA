class Solution {
public:
    bool isVowel(char ch) {
        // Convert to lowercase to handle uppercase vowels
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int si = 0, ei = 0;
        int vowelCount = 0, maxVowelCount = 0;

        while (ei < n) {

            // Add character at ei to the window
            if (isVowel(s[ei++]))
                vowelCount++;

            // Maintain window size exactly k
            if (ei - si == k) {

                // Update maximum vowels found
                maxVowelCount = max(maxVowelCount, vowelCount);

                // Remove character at si from the window
                if (isVowel(s[si++]))
                    vowelCount--;
            }
        }
        return maxVowelCount;
    }
};

/*dry run 
s = "abciiidef"
k = 3


Vowels = a e i o u

Initial State
si = 0
ei = 0
vowelCount = 0
maxVowelCount = 0


Window = ""

Step-by-Step Execution
🔹 Step 1

Add s[0] = 'a'

ei = 1

'a' is a vowel → vowelCount = 1

Window size = 1 → less than k
Window: "a"

🔹 Step 2

Add s[1] = 'b'

ei = 2

'b' is not a vowel → vowelCount = 1

Window size = 2 → less than k
Window: "ab"

🔹 Step 3

Add s[2] = 'c'

ei = 3

'c' is not a vowel → vowelCount = 1

Window size = 3 → equals k

✅ Update max:

maxVowelCount = max(0, 1) = 1


Remove s[0] = 'a':

'a' is vowel → vowelCount = 0

si = 1

Window: "bc"

🔹 Step 4

Add s[3] = 'i'

ei = 4

'i' is vowel → vowelCount = 1

Window size = 3

✅ Update max:

maxVowelCount = max(1, 1) = 1


Remove s[1] = 'b':

not vowel → vowelCount = 1

si = 2

Window: "ci"

🔹 Step 5

Add s[4] = 'i'

ei = 5

vowel → vowelCount = 2

Window size = 3

✅ Update max:

maxVowelCount = max(1, 2) = 2


Remove s[2] = 'c':

not vowel → vowelCount = 2

si = 3

Window: "ii"

🔹 Step 6

Add s[5] = 'i'

ei = 6

vowel → vowelCount = 3

Window size = 3

✅ Update max:

maxVowelCount = max(2, 3) = 3


Remove s[3] = 'i':

vowel → vowelCount = 2

si = 4

Window: "ii"

🔹 Step 7

Add s[6] = 'd'

ei = 7

not vowel → vowelCount = 2

Window size = 3

✅ Update max:

maxVowelCount = max(3, 2) = 3


Remove s[4] = 'i':

vowel → vowelCount = 1

si = 5

🔹 Step 8

Add s[7] = 'e'

ei = 8

vowel → vowelCount = 2

Window size = 3

✅ Update max:

maxVowelCount = max(3, 2) = 3


Remove s[5] = 'i':

vowel → vowelCount = 1

si = 6

🔹 Step 9

Add s[8] = 'f'

ei = 9

not vowel → vowelCount = 1

Window size = 3

✅ Update max:

maxVowelCount = max(3, 1) = 3

✅ Final Answer
maxVowelCount = 3


Substring: "iii"
*/