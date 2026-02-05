class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();

        // rem[r] = how many prefix sums had remainder r
        vector<int> rem(k, 0);

        int sum = 0;   // prefix sum
        int ans = 0;   // number of valid subarrays

        // remainder 0 occurs once before starting (empty prefix)
        rem[0] = 1;

        for (int ei = 0; ei < n; ei++) {

            sum += nums[ei];

            // handle negative numbers safely
            int r = (sum % k + k) % k;

            // all previous prefixes with same remainder form valid subarrays
            ans += rem[r];

            // record current remainder
            rem[r]++;
        }

        return ans;
    }
};

/*
nums = [4, 5, 0, -2, -3, 1]
k = 5

Initialize:
rem = [1, 0, 0, 0, 0]
sum = 0
ans = 0

------------------------------------------------
ei = 0, nums[0] = 4
sum = 4
r = 4

ans += rem[4] = 0   → ans = 0
rem = [1, 0, 0, 0, 1]

------------------------------------------------
ei = 1, nums[1] = 5
sum = 9
r = 4

ans += rem[4] = 1   → ans = 1
rem = [1, 0, 0, 0, 2]

------------------------------------------------
ei = 2, nums[2] = 0
sum = 9
r = 4

ans += rem[4] = 2   → ans = 3
rem = [1, 0, 0, 0, 3]

------------------------------------------------
ei = 3, nums[3] = -2
sum = 7
r = 2

ans += rem[2] = 0   → ans = 3
rem = [1, 0, 1, 0, 3]

------------------------------------------------
ei = 4, nums[4] = -3
sum = 4
r = 4

ans += rem[4] = 3   → ans = 6
rem = [1, 0, 1, 0, 4]

------------------------------------------------
ei = 5, nums[5] = 1
sum = 5
r = 0

ans += rem[0] = 1   → ans = 7
rem = [2, 0, 1, 0, 4]

------------------------------------------------
Final Answer = 7
*/
