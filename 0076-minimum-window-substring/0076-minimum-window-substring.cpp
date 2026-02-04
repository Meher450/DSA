class Solution {
public:
    string minWindow(string s, string t) {

        int ns = s.size(), nt = t.size();
        int count = 0;

        // Frequency array for characters in t
        vector<int> freq(128, 0);

        // Initialize frequency map and required character count
        for (int i = 0; i < nt; i++) {
            freq[t[i]]++;
            count++;                 // total characters needed
        }

        int si = 0, ei = 0;
        int len = INT_MAX;           // FIX 1: initialize to large value
        int gsi = 0;                 // starting index of best window

        while (ei < ns) {

            // Include s[ei] in window
            // If it was required (>0), reduce count
            if (freq[s[ei++]]-- > 0)
                count--;

            // When all required characters are included
            while (count == 0) {

                // Update minimum window
                if (ei - si < len) {
                    len = ei - si;
                    gsi = si;
                }

                // Remove s[si] from window
                // If it becomes required again, increase count
                if (freq[s[si++]]++ == 0)
                    count++;
            }
        }

        // FIX 2: if no valid window found
        return (len == INT_MAX) ? "" : s.substr(gsi, len);
    }
};
