class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int m = n / 2;
        
        // 1. Count character frequencies
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        
        // 2. Validate palindromic feasibility
        int odd_cnt = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_cnt++;
                mid_char = 'a' + i;
            }
        }
        if (odd_cnt > 1) return ""; // Cannot form any palindrome

        // Available pairs for the first half
        vector<int> half_cnt(26, 0);
        for (int i = 0; i < 26; ++i) half_cnt[i] = count[i] / 2;

        // Helper to reconstruct the full palindrome from the first half
        auto make_palindrome = [&](const string& half) {
            string res = half;
            if (n % 2 != 0) res += mid_char;
            string rev = half;
            reverse(rev.begin(), rev.end());
            return res + rev;
        };

        // 3. Try matching prefix of length i (from m down to 0)
        for (int i = m; i >= 0; --i) {
            vector<int> freq = half_cnt;
            bool valid = true;
            string prefix = "";
            
            // Match target[0...i-1]
            for (int j = 0; j < i; ++j) {
                int ch = target[j] - 'a';
                if (--freq[ch] < 0) {
                    valid = false;
                    break;
                }
                prefix += target[j];
            }
            if (!valid) continue;

            // Case A: Full first half match (i == m)
            if (i == m) {
                string full_pal = make_palindrome(prefix);
                if (full_pal > target) return full_pal;
                continue;
            }

            // Case B: Diverge at index i with a strictly larger character
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    vector<int> temp_freq = freq;
                    temp_freq[c]--;
                    string cand_half = prefix + (char)('a' + c);

                    // Fill remainder of first half with smallest available characters
                    for (int k = 0; k < 26; ++k) {
                        while (temp_freq[k] > 0) {
                            cand_half += (char)('a' + k);
                            temp_freq[k]--;
                        }
                    }
                    return make_palindrome(cand_half);
                }
            }
        }

        return "";
    }
};