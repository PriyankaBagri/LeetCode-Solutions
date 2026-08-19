class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return backtrack(s, dict, memo);
    }

private:
    vector<string> backtrack(const string& s, const unordered_set<string>& dict, 
                             unordered_map<string, vector<string>>& memo) {
        // Return cached results if available
        if (memo.count(s)) return memo[s];
        
        // Base case: empty string returns a vector with an empty string
        if (s.empty()) return {""};

        vector<string> result;

        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);

            if (dict.count(prefix)) {
                string suffix = s.substr(i);
                vector<string> suffixSentences = backtrack(suffix, dict, memo);

                for (const string& sentence : suffixSentences) {
                    string space = sentence.empty() ? "" : " ";
                    result.push_back(prefix + space + sentence);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};