class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0,diff=0;
        for(int i=0;i<nums.size();i++)
        mx=max(mx,nums[i]);
        for(int i=0;i<nums.size();i++)
        diff=diff+(mx-nums[i]);
        return diff;
    }
};