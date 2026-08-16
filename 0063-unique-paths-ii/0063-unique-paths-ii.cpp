class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<long long> dp(n, 0);
        dp[0] = 1; // Start position

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle blocks all paths to this cell
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Combine top and left paths
                }
            }
        }

        return dp[n - 1];
    }
};