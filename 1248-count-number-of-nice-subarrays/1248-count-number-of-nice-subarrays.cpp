class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     unordered_map<int, int> count_map;
        count_map[0] = 1; // Base case: prefix sum of 0 occurs once initially

        int curr_odd = 0;
        int total_nice = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                curr_odd++;
            }

            if (count_map.count(curr_odd - k)) {
                total_nice += count_map[curr_odd - k];
            }

            // Record current prefix sum of odd counts
            count_map[curr_odd]++;
        }

        return total_nice;   
    }
};