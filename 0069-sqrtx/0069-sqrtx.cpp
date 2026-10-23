class Solution {
public:
    int mySqrt(int x) {
       if (x == 0 || x == 1) {
        return x;
    }

    long long low = 1, high = x, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Check if mid squared is less than or equal to x
        if (mid <= x / mid) {
            ans = mid;           // Store valid candidate
            low = mid + 1;       // Try to find a larger integer root
        } else {
            high = mid - 1;      // Search lower half
        }
    }

    return ans;

    }
};