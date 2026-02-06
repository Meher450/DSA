class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(), ei=n-1 ,si=0, sum=0;
        while(ei<n){
            sum=nums[si]+nums[ei];
            if(sum==target){
                return {si+1,ei+1};
            }else if(sum<target) si++;
            else ei--;
        }
        return {-1,-1};
    }
};