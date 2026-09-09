class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Buckets where index represents frequency
        vector<vector<int>> buckets(n + 1);
        for (const auto& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        std::vector<int> result;
        // Gather k elements starting from highest frequency bucket
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};