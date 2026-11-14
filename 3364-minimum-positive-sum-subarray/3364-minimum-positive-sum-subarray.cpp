class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
      int n=nums.size();
      int i,j;
      int mn=INT_MAX;
      for(i=0;i<n;i++)
      {
        int sum=0;
        for(j=i;j<n;j++)
        {
            sum=sum+nums[j];
            int len=j-i+1;
            if(len>=l&&len<=r&&sum>0)
            mn=min(mn,sum);
        }
      } 
      if(mn==INT_MAX)
      return -1;
      else
      return mn; 
    }
};