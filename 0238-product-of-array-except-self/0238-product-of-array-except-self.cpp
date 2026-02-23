class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(nums[j]!=nums[i]) sum*=nums[j];
            }
            ans[i]=sum;
        }
        return ans;
    }
};