class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
         vector<int> d;
        long long k = (long long)k1 + k2;
        long long sum = 0;

        for(int i = 0; i < nums1.size(); i++)
        {
            d.push_back(abs(nums1[i] - nums2[i]));
            sum += d.back();
        }

        if(sum <= k)
            return 0;
int l = 0, r = 100000;

while(l < r)
{
    int mid = l + (r - l) / 2;
    long long need = 0;

    for(int x : d)
        need += max(0, x - mid);

    if(need <= k)
        r = mid;
    else
        l = mid + 1;
}

        long long ans = 0, rem = k;

        for(int x : d)
        {
            int y = min(x, l);
            ans += 1LL * y * y;
            rem -= x - y;
        }

        ans -= rem * (2 * l - 1);

        return ans;
    }
};