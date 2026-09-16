class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int totalLeft = (m + n + 1) / 2;

        while (low <= high) {

            // Number of elements taken from nums1
            int cut1 = low + (high - low) / 2;

            // Number of elements taken from nums2
            int cut2 = totalLeft - cut1;

            // Boundary values
            int left1 = (cut1 == 0) ? INT_MIN: nums1[cut1 - 1];

            int right1 = (cut1 == m)  ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN: nums2[cut2 - 1];

            int right2 = (cut2 == n) ? INT_MAX: nums2[cut2];

            
            if (left1 <= right2 && left2 <= right1) {

                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                
                return (max(left1, left2)
                        + min(right1, right2)) / 2.0;
            }

           
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;

    }
};