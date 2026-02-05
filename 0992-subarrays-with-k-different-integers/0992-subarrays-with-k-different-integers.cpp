class Solution {
public:
    int atMostDistinct(vector<int> &arr,int k){
        int n=arr.size(), si=0, ei=0, count=0, subArrayCount=0;
        vector<int>freq(n+1,0);

        while(ei<n){
            if(freq[arr[ei++]]++ == 0) count++;
            while(count > k){
                if(freq[arr[si++]]-- == 1) count--;
            }
            subArrayCount += ei-si;
        }
        return subArrayCount;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMostDistinct(arr,k) - atMostDistinct(arr,k-1);
    }
};