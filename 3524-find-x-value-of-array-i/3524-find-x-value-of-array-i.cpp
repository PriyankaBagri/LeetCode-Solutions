class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>ans(k,0);
        vector<long long>dp(k,0);
        for(int x:nums){
            vector<long long>newdp(k,0);
            newdp[x%k]++;
            for(int r=0;r<k;r++){
            newdp[(r*(x%k))%k]+=dp[r];
            }
            dp=newdp;
            for(int r=0;r<k;r++)
            {
                ans[r]+=dp[r];
            }      
              }
              return ans;
    }
};