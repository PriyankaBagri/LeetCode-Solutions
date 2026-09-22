class Solution {
    struct Node {
        int prod = 1;
        int cnt[5] = {0}; // k is at most 5, so size 5 is enough
    };

    int K;
    int n;
    vector<Node> tree;

    // Merge Left child and Right child into a Parent node
    Node merge(const Node& L, const Node& R) {
        Node parent;
        parent.prod = (L.prod * R.prod) % K;

        // 1. Prefixes entirely inside the Left child
        for (int r = 0; r < K; ++r) {
            parent.cnt[r] = L.cnt[r];
        }

        // 2. Prefixes that extend into the Right child
        for (int r = 0; r < K; ++r) {
            if (R.cnt[r] > 0) {
                int combined_rem = (L.prod * r) % K;
                parent.cnt[combined_rem] += R.cnt[r];
            }
        }

        return parent;
    }

    // Build initial tree
    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int rem = nums[start] % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % K;
            for (int r = 0; r < K; ++r) tree[node].cnt[r] = 0; // Reset
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }
        Node leftRes = query(2 * node, start, mid, l, r);
        Node rightRes = query(2 * node + 1, mid + 1, end, l, r);
        return merge(leftRes, rightRes);
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int starti = q[2];
            int xi = q[3];
            update(1, 0, n - 1, idx, val);
            Node ansNode = query(1, 0, n - 1, starti, n - 1);

            result.push_back(ansNode.cnt[xi]);
        }

        return result;
    }
};