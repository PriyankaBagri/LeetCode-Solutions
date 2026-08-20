class Solution {
    private:
    bool dfs(const vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] > target) {
                continue;
            }

            // Pruning: Skip checking redundant sides with the same length
            bool skip = false;
            for (int j = 0; j < i; ++j) {
                if (sides[j] == sides[i]) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;

            sides[i] += matchsticks[index];

            if (dfs(matchsticks, sides, index + 1, target)) {
                return true;
            }

            sides[i] -= matchsticks[index];
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;

        long long sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        if (sum % 4 != 0) return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target) return false;

        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, 0, target);
    }
};