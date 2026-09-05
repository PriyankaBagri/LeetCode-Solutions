class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if s[i..m-1] matches p[j..n-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[m][n] = true;
        
        // Fill the DP table bottom-up
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
                
                if (j + 1 < n && p[j + 1] == '*') {
                    // Two options for '*':
                    // 1. Ignore the character and '*' (match 0 times) -> dp[i][j + 2]
                    // 2. Consume character from s if first_match is true -> dp[i + 1][j]
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        
        return dp[0][0];
    }
};