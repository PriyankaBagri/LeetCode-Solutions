class Solution {
public:
       using ll = long long;

    struct Node {
        ll score = 0;
        vector<int> ids;
    };

    // Return the better of two choices
    Node better(Node a, Node b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        if (a.ids.size() != b.ids.size()) {
            // Not actually needed for this problem's lexicographic
            // comparison, but keeping normal vector comparison is enough.
        }

        return (a.ids < b.ids ? a : b);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
                int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<ll, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by left endpoint
        sort(a.begin(), a.end());

        vector<ll> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        // nxt[i] = first interval with left > right[i]
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] =
                upper_bound(starts.begin(), starts.end(), a[i][1])
                - starts.begin();
        }

        /*
            dp[k][i] =
            best answer using at most k intervals
            from sorted position i onward.
        */
        vector<vector<Node>> dp(5, vector<Node>(n + 1));

        for (int k = 1; k <= 4; k++) {

            for (int i = n - 1; i >= 0; i--) {

                // Option 1: don't take interval i
                Node skip = dp[k][i + 1];

                // Option 2: take interval i
                Node take = dp[k - 1][nxt[i]];

                take.score += a[i][2];

                // Add original index
                take.ids.push_back((int)a[i][3]);

                // The answer must be sorted by original index
                sort(take.ids.begin(), take.ids.end());

                dp[k][i] = better(take, skip);
            }
        }

        return dp[4][0].ids;

    }
};