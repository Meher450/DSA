class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Step 1: Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0, high = n;

        // Step 2: Binary search
        while (low <= high) {

            // mid1 = partition index in nums1
            int mid1 = low + (high - low) / 2;

            // mid2 = partition index in nums2
            int mid2 = (n + m + 1) / 2 - mid1;

            // Step 3: Handle boundaries using INT_MIN and INT_MAX
            int left1  = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int left2  = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int right1 = (mid1 == n) ? INT_MAX : nums1[mid1];
            int right2 = (mid2 == m) ? INT_MAX : nums2[mid2];

            // Step 4: Check if valid partition
            if (left1 <= right2 && left2 <= right1) {

                // Step 5: Compute median
                if ((n + m) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            }

            // Move partition left
            else if (left1 > right2) {
                high = mid1 - 1;
            }

            // Move partition right
            else {
                low = mid1 + 1;
            }
        }

        return 0.0; // safety return
    }
};
