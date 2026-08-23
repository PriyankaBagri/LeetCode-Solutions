class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int res = nums.size(); // Default position if target is larger than all elements
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) { // Covers both equal and greater cases
            res = i;
            break;
        }
    }
    
    return res;
    }
};