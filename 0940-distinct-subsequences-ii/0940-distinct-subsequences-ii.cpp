class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        int MOD = 1e9 + 7;
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; 
        
     vector<int> last(26, -1);
        
        for (int i = 1; i <= n; ++i) {
            char c = s[i - 1];
            int char_idx = c - 'a';
            
          
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            if (last[char_idx] != -1) {
                int prev_idx = last[char_idx];
                dp[i] = (dp[i] - dp[prev_idx - 1] + MOD) % MOD;
            }
            
           
            last[char_idx] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};