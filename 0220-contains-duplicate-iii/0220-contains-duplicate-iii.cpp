class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
      if (indexDiff < 1 || valueDiff < 0) return false;

        unordered_map<long long, long long> b_map;
        long long w = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); ++i) {
            long long val = nums[i];
            long long b_id = val < 0 ? (val + 1) / w - 1 : val / w;

            
            if (b_map.count(b_id)) return true;

           
            if (b_map.count(b_id - 1) && abs(val - b_map[b_id - 1]) <= valueDiff) return true;

            
            if (b_map.count(b_id + 1) && abs(val - b_map[b_id + 1]) <= valueDiff) return true;

           
            b_map[b_id] = val;

            
            if (i >= indexDiff) {
                long long old_val = nums[i - indexDiff];
                long long old_b_id = old_val < 0 ? (old_val + 1) / w - 1 : old_val / w;
                b_map.erase(old_b_id);
            }
        }

        return false;  
    }
};