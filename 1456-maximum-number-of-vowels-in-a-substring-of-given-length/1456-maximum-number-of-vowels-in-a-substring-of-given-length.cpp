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
