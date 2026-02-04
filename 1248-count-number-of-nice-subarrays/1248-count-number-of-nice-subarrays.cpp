class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int count = 0;

        for(int r = 0; r < n; r++){
            if(nums[r] & 2 != 0) k--;

            while(k < 0){
                if(nums[l] & 2 != 0) k++;
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


/*
Dry Run
Example
nums = [1, 1, 2, 1, 1]
k = 3


Odds are 1,1,1,1

Dry run: atmost(nums, 3)
r	nums[r]	odd?	k	l	subarrays added	total
0	1	yes	2	0	1	1
1	1	yes	1	0	2	3
2	2	no	1	0	3	6
3	1	yes	0	0	4	10
4	1	yes	-1	1	4	14

✅ atmost(3) = 14

Dry run: atmost(nums, 2)
r	nums[r]	odd?	k	l	subarrays added	total
0	1	yes	1	0	1	1
1	1	yes	0	0	2	3
2	2	no	0	0	3	6
3	1	yes	-1	1	3	9
4	1	yes	-1	3	2	11

✅ atmost(2) = 11

Final Answer
exactly 3 odds = 14 − 11 = 3
*/