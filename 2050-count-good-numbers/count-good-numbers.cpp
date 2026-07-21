class Solution {
    const int MOD = 1e9 + 7;
public:

    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        // Binary Exponentiation for 5^evenPositions % MOD
        long long evens = 1, base5 = 5;
        while (evenPositions > 0) {
            if (evenPositions % 2 == 1) evens = (evens * base5) % MOD;
            base5 = (base5 * base5) % MOD;
            evenPositions /= 2;
        }

        // Binary Exponentiation for 4^oddPositions % MOD
        long long odds = 1, base4 = 4;
        while (oddPositions > 0) {
            if (oddPositions % 2 == 1) odds = (odds * base4) % MOD;
            base4 = (base4 * base4) % MOD;
            oddPositions /= 2;
        }

        return (evens * odds) % MOD;
    }
};