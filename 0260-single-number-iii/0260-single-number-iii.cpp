class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long xorr=0;
        for(int i=0;i<n;i++)
        {
           xorr=xorr^nums[i];
        }
        int right=0;
        right=(xorr&(xorr-1))^xorr;
        int xorr1=0,xorr2=0;
        for(int i=0; i < n; i++) {
            
            /* Divide the numbers among bucket 1
             and 2 based on rightmost set bit */
            if(nums[i] & right) {
                xorr1 = xorr1 ^ nums[i];
            }
            else {
                xorr2 = xorr2 ^ nums[i];
            }
        }
        
if(xorr1 < xorr2)
 return {xorr1, xorr2};
        return {xorr2, xorr1};
    }
};