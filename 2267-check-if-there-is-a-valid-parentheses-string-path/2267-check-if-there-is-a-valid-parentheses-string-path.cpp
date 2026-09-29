class Solution {
public:

    bool hasValidPath(vector<vector<char>>& grid) {
   int m = grid.size();
        int n = grid[0].size();

        // Parity check: length of any path is m + n - 1 (must be even)
        if ((m + n - 1) % 2 != 0) return false;
        // Start must be '(' and end must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // dp[c] stores the bitset of possible balances for the current row at column c
        // Max balance cannot exceed (m + n) / 2
        vector<bitset<105>> dp(n);

        // Base case: starting cell (0, 0)
        dp[0][1] = 1; // grid[0][0] is '(', so balance is 1

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) continue;

                bitset<105> current;
                // Coming from the top cell (r - 1, c)
                if (r > 0) current |= dp[c];
                // Coming from the left cell (r, c - 1)
                if (c > 0) current |= dp[c - 1];

                // Update balance with the current character
                if (grid[r][c] == '(') {
                    dp[c] = current << 1;
                } else {
                    dp[c] = current >> 1;
                }
            }
        }

        // At destination (m - 1, n - 1), check if a balance of 0 is achievable (bit 0 is set)
        return dp[n - 1][0];
    }
};