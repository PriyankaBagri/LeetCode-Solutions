class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        int inc = 1, dec = 1;
        int max_len = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            max_len = max(max_len, max(inc, dec));
        }

        return max_len;
    }
};