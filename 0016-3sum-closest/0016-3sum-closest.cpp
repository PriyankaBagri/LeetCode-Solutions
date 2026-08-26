class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize closest_sum with the sum of the first triplet
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                // Exact match found - cannot get closer than 0 difference
                if (current_sum == target) {
                    return current_sum;
                }

                // Update closest_sum if current_sum is closer to target
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }

                // Adjust pointers to get closer to target
                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest_sum;
       
    }
};