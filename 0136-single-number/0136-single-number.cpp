class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size=nums.size();
        int xorr=0;
        for(int i=0;i<size;i++)
        {
             xorr=xorr^nums[i];
        }
        return xorr;
    }
};