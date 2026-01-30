class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Minimum lies in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum lies in the left half (including mid)
            else {
                high = mid;
            }
        }

        // low == high, pointing to minimum element
        return nums[low];
    }
};
