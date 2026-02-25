class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long ans=0;
        int rev=x;
        while(rev!=0){
            int digit=rev%10;
            ans=ans*10+digit;
            rev=rev/10;
        }
        return (int)ans == x;
    }
};