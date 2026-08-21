class Solution {
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    // Helper function to calculate Least Common Multiple
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // Counts how many amounts <= x can be formed using inclusion-exclusion
    long long count_amounts(long long x, const vector<int>& coins) {
        long long total = 0;
        int n = coins.size();

        // Iterate through all 2^n - 1 non-empty subsets of coins
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long curr_lcm = 1;
            int bit_cnt = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bit_cnt++;
                    curr_lcm = lcm(curr_lcm, coins[i]);
                    // Break early if LCM exceeds x to prevent overflow
                    if (curr_lcm > x) break;
                }
            }

            if (bit_cnt % 2 != 0) {
                total += x / curr_lcm;
            } else {
                total -= x / curr_lcm;
            }
        }

        return total;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (count_amounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; // Try finding a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};