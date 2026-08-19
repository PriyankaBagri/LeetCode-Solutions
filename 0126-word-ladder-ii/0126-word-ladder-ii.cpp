class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};

        // BFS setup
        unordered_map<string, int> dist;
        unordered_map<string, vector<string>> parentMap;
        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        bool found = false;
        int wordLen = beginWord.length();

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            int currentDist = dist[current];

            // If we found endWord and processed nodes beyond its distance, stop
            if (found && currentDist >= dist[endWord]) break;

            string temp = current;
            for (int i = 0; i < wordLen; ++i) {
                char originalChar = temp[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;
                    temp[i] = c;

                    if (dict.count(temp)) {
                        // If unvisited, set distance and push to queue
                        if (!dist.count(temp)) {
                            dist[temp] = currentDist + 1;
                            q.push(temp);
                            parentMap[temp].push_back(current);

                            if (temp == endWord) found = true;
                        } 
                        // If visited at the same shortest distance level, record as valid parent
                        else if (dist[temp] == currentDist + 1) {
                            parentMap[temp].push_back(current);
                        }
                    }
                }
                temp[i] = originalChar;
            }
        }

        if (!found) return {};

        // Reconstruct paths from endWord to beginWord via DFS
        vector<vector<string>> result;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parentMap, path, result);

        return result;
    }

private:
    void dfs(const string& word, const string& beginWord,
             unordered_map<string, vector<string>>& parentMap,
             vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> currentPath = path;
            reverse(currentPath.begin(), currentPath.end());
            result.push_back(currentPath);
            return;
        }

        for (const string& parent : parentMap[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, parentMap, path, result);
            path.pop_back();
        }
    }
};