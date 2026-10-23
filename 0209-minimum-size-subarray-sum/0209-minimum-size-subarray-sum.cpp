class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow=0,sum=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                
                ans=min(ans,i-slow+1);
                sum-=nums[slow];
                slow++;
            }
        }
         return ans == INT_MAX ? 0 : ans;
    }
};