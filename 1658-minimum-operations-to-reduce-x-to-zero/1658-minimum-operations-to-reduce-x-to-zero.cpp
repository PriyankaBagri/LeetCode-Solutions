class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long t=0,c=0,r,i,l=0,max_l=-1,sum=0;
        for(i=0;i<n;i++)
        sum=sum+nums[i];
        t=sum-x;
        if(t==0)
        return n;
        if(t<0)
        return -1;
        for(r=0;r<n;++r)
        {
            c=c+nums[r];
            while(c>t&&l<=r)
            {
                c=c-nums[l];
                l++;
            }
            if(c==t)
            {
                max_l=max(max_l,r-l+1);
            }
        }
        return (max_l==-1)?-1:n-max_l;
    }
};