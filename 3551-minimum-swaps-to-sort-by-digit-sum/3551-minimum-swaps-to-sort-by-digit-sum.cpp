class Solution {
public:
int digitSum(int x)
{
    int s=0;
    while(x>0)
    {
    int r=x%10;
     s=s+r;
    x=x/10;
    }
    return s;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        v.push_back({nums[i],i});
        sort(v.begin(),v.end(),[&](auto a,auto b)
        {
            int x=digitSum(a.first);
            int y=digitSum(b.first);
            if(x==y)
            return a.first<b.first;
            return x<y;
        });
                vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i)
                continue;

            int j = i, cnt = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;

    }
};