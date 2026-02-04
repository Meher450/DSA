class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), si=0,ei=0,len=0,count=0;
        vector<int> freq(128,0);
        
        while(ei<n){
            if(freq[s[ei++]]++==1) count++;
            //freq[s[ei]]++;
            //ei++;

            while(count==1){
                if(freq[s[si++]]-- ==2) count--;
                //freq[s[si]]--;
                //si++;
            }

            len=max(len,ei-si);
        }
        return len;
    }
};