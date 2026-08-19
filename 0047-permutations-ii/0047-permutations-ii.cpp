class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);

        // Sort to bring duplicate elements together
        sort(nums.begin(), nums.end());

        backtrack(nums, visited, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& visited,
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: formed a full permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip already used elements
            if (visited[i]) continue;

            // Skip duplicate elements to avoid generating duplicate permutations
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            // Choose
            visited[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, visited, current, result);

            // Backtrack
            current.pop_back();
            visited[i] = false;
        }
    }
};