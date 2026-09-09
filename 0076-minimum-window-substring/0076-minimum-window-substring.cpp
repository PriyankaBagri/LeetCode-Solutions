class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> targetCount;
        for (char c : t) {
            targetCount[c]++;
        }

        int required = targetCount.size(); // Number of unique characters needed
        int formed = 0;                    // Unique characters meeting target frequency

        unordered_map<char, int> windowCount;
        
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            // If the current character's count matches target count, increment formed
            if (targetCount.count(c) && windowCount[c] == targetCount[c]) {
                formed++;
            }

            // Try to shrink window from the left once all characters are present
            while (left <= right && formed == required) {
                char leftChar = s[left];

                // Update minimum window result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // Remove character from left of window
                windowCount[leftChar]--;
                if (targetCount.count(leftChar) && windowCount[leftChar] < targetCount[leftChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
    
};