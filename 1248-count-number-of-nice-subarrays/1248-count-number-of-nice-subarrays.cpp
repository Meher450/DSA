class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int count = 0;

        for(int r = 0; r < n; r++){
            if(nums[r] % 2 != 0) k--;

            while(k < 0){
                if(nums[l] % 2 != 0) k++;
                l++;
            }

            count += r - l + 1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};