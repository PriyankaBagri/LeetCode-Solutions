class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
     int n = nums.size();
        
        int min_idx = 0;
        int max_idx = 0;

        // Find indices of minimum and maximum elements
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[min_idx]) min_idx = k;
            if (nums[k] > nums[max_idx]) max_idx = k;
        }

        // i is the smaller index (closer to start), j is the larger index (closer to end)
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        // 3 Possible Choices:
        int option1 = j + 1;             // Both deleted from front
        int option2 = n - i;             // Both deleted from back
        int option3 = (i + 1) + (n - j); // One from front, one from back

        return min({option1, option2, option3});
    }
};