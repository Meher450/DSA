#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int si = 0;
        int ei = s.size() - 1;

        while (si < ei) {
            while (!isalnum(s[si])) si++;
            while (!isalnum(s[ei])) ei--;

            if (tolower(s[si]) != tolower(s[ei]))
                return false;

            si++;
            ei--;
        }
        return true;
    }
};