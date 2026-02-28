class Solution {
public:
    int countDigitOne(int n) {
        int count=0;
        for(long i=1;i<=n;i*=10){
            long rem=n/i;
            long m=n%i;
            count +=(rem+8)/10 * i + (rem%10==1?m+1:0);
        }
        return count;
    }
};

/*



*/