class Solution {
public:
 int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {

        if (l > r)
            return 0;

        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        // Option 1:
        // Remove boxes[r] along with k boxes of the same color
        int ans = (k + 1) * (k + 1)
                + solve(boxes, l, r - 1, 0);

        // Option 2:
        // Try to merge boxes[r] with another box of same color
        for (int i = l; i < r; i++) {

            if (boxes[i] == boxes[r]) {

                int middle = solve(boxes, i + 1, r - 1, 0);

                int merged = solve(boxes, l, i, k + 1);

                ans = max(ans, middle + merged);
            }
        }

        return dp[l][r][k] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));

        int n = boxes.size();

        return solve(boxes, 0, n - 1, 0);
    }
};