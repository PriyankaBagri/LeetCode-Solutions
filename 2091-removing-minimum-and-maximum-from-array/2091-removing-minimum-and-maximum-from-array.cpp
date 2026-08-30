class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
      int n = nums.size();
        if (n == 1) return 1;

        int min_idx = 0;
        int max_idx = 0;

        // Step 1: Find indices of min and max elements
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[min_idx]) min_idx = k;
            if (nums[k] > nums[max_idx]) max_idx = k;
        }

        // i is closer to the front, j is further from the front
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        // Option 1: Both from front
        int both_front = j + 1;
        
        // Option 2: Both from back
        int both_back = n - i;
        
        // Option 3: One from front, one from back
        int front_and_back = (i + 1) + (n - j);

        // Return minimum of all 3 strategies
        return min({both_front, both_back, front_and_back});
    }
};