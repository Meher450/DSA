class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;
    }
};

/*
==================== DRY RUN ====================

Input:
nums = [1,2,3,4]
index   0 1 2 3

--------------------------------------------------
STEP 1: PREFIX BUILD

Initial:
ans = [1,1,1,1]

i = 1:
ans[1] = ans[0] * nums[0]
       = 1 * 1
       = 1
ans = [1,1,1,1]

i = 2:
ans[2] = ans[1] * nums[1]
       = 1 * 2
       = 2
ans = [1,1,2,1]

i = 3:
ans[3] = ans[2] * nums[2]
       = 2 * 3
       = 6
ans = [1,1,2,6]

Now:
ans[i] = product of elements before i

--------------------------------------------------
STEP 2: SUFFIX MULTIPLICATION

Initial:
suffix = 1

i = 3:
ans[3] *= suffix
       = 6 * 1
       = 6
suffix *= nums[3]
       = 1 * 4
       = 4
ans = [1,1,2,6]

i = 2:
ans[2] *= suffix
       = 2 * 4
       = 8
suffix *= nums[2]
       = 4 * 3
       = 12
ans = [1,1,8,6]

i = 1:
ans[1] *= suffix
       = 1 * 12
       = 12
suffix *= nums[1]
       = 12 * 2
       = 24
ans = [1,12,8,6]

i = 0:
ans[0] *= suffix
       = 1 * 24
       = 24
suffix *= nums[0]
       = 24 * 1
       = 24
ans = [24,12,8,6]

--------------------------------------------------

Final Output:
[24,12,8,6]

Meaning:
Index 0 → 2*3*4 = 24
Index 1 → 1*3*4 = 12
Index 2 → 1*2*4 = 8
Index 3 → 1*2*3 = 6

==================================================
*/