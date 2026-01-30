class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // If slope is increasing, peak lies on the right
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            // If slope is decreasing, peak lies on the left or at mid
            else {
                high = mid;
            }
        }

        // low == high, pointing to a peak index
        return low;
    }
};
