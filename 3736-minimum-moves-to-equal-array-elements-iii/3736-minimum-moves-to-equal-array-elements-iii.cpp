class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int counter=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            counter+=abs(nums[i]-nums[n-1]);
        }
        return counter;
    }
};