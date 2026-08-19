class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true; // Minimum removals reached for this level
            }

            // Once valid string(s) are found at this level, stop exploring deeper levels
            if (found) continue;

            for (int i = 0; i < current.length(); ++i) {
                // Only remove parenthesis characters
                if (current[i] != '(' && current[i] != ')') continue;

                // Create substring by removing character at index i
                string nextStr = current.substr(0, i) + current.substr(i + 1);

                if (!visited.count(nextStr)) {
                    visited.insert(nextStr);
                    q.push(nextStr);
                }
            }
        }

        return result;
    }

private:
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }
};