class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // 1. Pair each value with its original index
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        // 2. Sort pairs by value
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> result(n);
        int i = 0;
        
        // 3. Process connected components (groups)
        while (i < n) {
            int j = i;
            
            // Find the boundary of the current connected component
            while (j + 1 < n && sorted_nums[j + 1].first - sorted_nums[j].first <= limit) {
                j++;
            }
            
            // Collect original indices for elements in this group
            vector<int> group_indices;
            for (int k = i; k <= j; ++k) {
                group_indices.push_back(sorted_nums[k].second);
            }
            
            // Sort original indices ascending
            sort(group_indices.begin(), group_indices.end());
            
            // Place values into sorted original positions
            for (int k = 0; k < group_indices.size(); ++k) {
                result[group_indices[k]] = sorted_nums[i + k].first;
            }
            
            // Move to next group
            i = j + 1;
        }
        
        return result;
    }
};