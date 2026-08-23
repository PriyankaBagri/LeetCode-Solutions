class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0,fast=0;
        while(fast<nums.size())
        {
            if(nums[fast]!=val){
            nums[slow]=nums[fast];
            slow=slow+1;
            }
            fast=fast+1;
        }
        return slow;
    }
};