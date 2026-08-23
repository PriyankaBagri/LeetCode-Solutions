class Solution {
public:
    bool sumGame(string num) {
                      int n = num.length();
        int mid = n / 2;
        
        int sum_left = 0, q_left = 0;
        int sum_right = 0, q_right = 0;
        
        // Accumulate sums and counts for the left half
        for (int i = 0; i < mid; ++i) {
            if (num[i] == '?') {
                q_left++;
            } else {
                sum_left += num[i] - '0';
            }
        }
        
        // Accumulate sums and counts for the right half
        for (int i = mid; i < n; ++i) {
            if (num[i] == '?') {
                q_right++;
            } else {
                sum_right += num[i] - '0';
                            }
        }
        
        // Bob wins if the equation holds true; otherwise, Alice wins.
        return 2 * (sum_left - sum_right) != 9 * (q_right - q_left);


    }
};