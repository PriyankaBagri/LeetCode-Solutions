class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int k=1;k<=n;k++)
        {
            if(n % k !=0)
            continue;
            bool ok=true;
            int prev=-1;
            for(int st=0;st<n;st+=k)
            {
                int mn=nums[st],mx=nums[st];
                int cnt=0;
                for(int i=st;i<st+k;i++)
                {
                    mx=max(nums[i],mx);
                    mn=min(nums[i],mn);
                    int j=(i+1==st+k)?st:i+1;
                    if(nums[i]>nums[j])
                    cnt++;
                }
                if(cnt>1||prev>mn)
                {
                    ok=false;
                    break;
                }
                prev=mx;
            }
              if(ok)
        ans+=k;

        }
      return ans;
    }
};