class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Telephone keypad mapping
        const vector<string> pad = {
            "",     "",     "abc",  "def", // 0, 1, 2, 3
            "ghi",  "jkl",  "mno",         // 4, 5, 6
            "pqrs", "tuv",  "wxyz"         // 7, 8, 9
        };

        vector<string> result;
        string current = "";

        backtrack(digits, 0, current, result, pad);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const vector<string>& pad) {
        // Base case: formed a combination of full length
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get matching letters for current digit
        string letters = pad[digits[index] - '0'];

        for (char c : letters) {
            current.push_back(c);                      // Choose
            backtrack(digits, index + 1, current, result, pad); // Explore
            current.pop_back();                       // Backtrack
        }
    }
};