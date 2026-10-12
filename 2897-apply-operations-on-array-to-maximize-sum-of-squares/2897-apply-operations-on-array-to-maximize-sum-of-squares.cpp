class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        vector<int> cnt(31, 0);

        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if ((x >> b) & 1) {
                    cnt[b]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % mod;
        }

        return ans;

    }
};