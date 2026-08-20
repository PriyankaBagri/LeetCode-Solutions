class Solution {
    private:
    void dfs(int u, int target, const vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        if (u == target) {
            result.push_back(path);
            return;
        }

        for (int v : graph[u]) {
            path.push_back(v);
            dfs(v, target, graph, path, result);
            path.pop_back(); // Backtrack
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<std::vector<int>> result;
        vector<int> path = {0};
        
        dfs(0, graph.size() - 1, graph, path, result);
        
        return result;
    }
};