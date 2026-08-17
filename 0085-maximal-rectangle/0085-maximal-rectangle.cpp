class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int r_cnt = matrix.size();
        int c_cnt = matrix[0].size();
        vector<int> h_arr(c_cnt, 0);
        int max_area = 0;

        for (int r = 0; r < r_cnt; ++r) {
            // Update heights for current row
            for (int c = 0; c < c_cnt; ++c) {
                if (matrix[r][c] == '1') {
                    h_arr[c]++;
                } else {
                    h_arr[c] = 0;
                }
            }

            // Monotonic stack to find largest rectangle in histogram
            stack<int> st_idx;
            for (int c = 0; c <= c_cnt; ++c) {
                int curr_h = (c == c_cnt) ? 0 : h_arr[c];
                while (!st_idx.empty() && h_arr[st_idx.top()] >= curr_h) {
                    int height = h_arr[st_idx.top()];
                    st_idx.pop();
                    int width = st_idx.empty() ? c : (c - st_idx.top() - 1);
                    max_area = max(max_area, height * width);
                }
                st_idx.push(c);
            }
        }

        return max_area;
        
    }
};