class Solution {
public:
    int balancedString(string s) {
      int n = s.length();
        int k = n / 4;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Check if string is already balanced
        if (freq['Q'] <= k && freq['W'] <= k && freq['E'] <= k && freq['R'] <= k) {
            return 0;
        }

        int min_len = n;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            freq[s[r]]--;

            // Shrink window while all character frequencies outside are <= k
            while (l <= r && freq['Q'] <= k && freq['W'] <= k && freq['E'] <= k && freq['R'] <= k) {
                min_len = min(min_len, r - l + 1);
                freq[s[l]]++;
                l++;
            }
        }

        return min_len;  
    }
};