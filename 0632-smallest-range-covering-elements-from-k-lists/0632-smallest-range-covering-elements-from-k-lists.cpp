class Solution {
    struct Element {
        int val;
        int row;
        int col;

        bool operator>(const Element& other) const {
            return val > other.val;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Element, vector<Element>, greater<Element>> min_heap;

        int curr_max = INT_MIN;
        for (int i = 0; i < k; ++i) {
            min_heap.push({nums[i][0], i, 0});
            curr_max = max(curr_max, nums[i][0]);
        }

        int start_r = 0, end_r = INT_MAX;

        while (min_heap.size() == k) {
            auto [val, r, c] = min_heap.top();
            min_heap.pop();

            // Update range if a smaller one is found
            if (curr_max - val < end_r - start_r) {
                start_r = val;
                end_r = curr_max;
            }

            // Move to the next element in the same list
            if (c + 1 < nums[r].size()) {
                int next_val = nums[r][c + 1];
                min_heap.push({next_val, r, c + 1});
                curr_max = max(curr_max, next_val);
            }
        }

        return {start_r, end_r};
    }
};