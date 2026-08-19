class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }

private:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result) {
        // Base case: formed a full permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);       // Choose: swap element into current position
            backtrack(start + 1, nums, result);  // Explore: move to next position
            swap(nums[start], nums[i]);       // Backtrack: restore original array state
        }
    }
};