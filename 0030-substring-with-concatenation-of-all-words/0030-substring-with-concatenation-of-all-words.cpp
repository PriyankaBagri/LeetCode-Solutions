class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        // Build word frequency map for target words
        unordered_map<string, int> wordCount;
        for (const string& w : words) {
            wordCount[w]++;
        }

        // Try every offset from 0 to wordLen - 1
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int count = 0; // Number of valid words matched in current window
            unordered_map<string, int> currentMap;

            // Slide the window by steps of wordLen
            while (right + wordLen <= sLen) {
                string sub = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.count(sub)) {
                    currentMap[sub]++;
                    count++;

                    // If word frequency exceeds target, shrink window from left
                    while (currentMap[sub] > wordCount[sub]) {
                        string leftSub = s.substr(left, wordLen);
                        currentMap[leftSub]--;
                        count--;
                        left += wordLen;
                    }

                    // If all words are matched exactly
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word encountered, reset window
                    currentMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
    