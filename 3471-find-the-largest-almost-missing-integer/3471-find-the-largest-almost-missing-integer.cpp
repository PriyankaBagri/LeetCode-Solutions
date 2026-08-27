class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> subarray_count;
        for(int i=0;i<=n-k;++i)
        {
            unordered_set<int> unique;
            for(int j=i;j<i+k;++j)
            {
                unique.insert(nums[j]);
            }
            for(int num:unique)
            {
                subarray_count[num]++;
            }
        }
        int result = -1;
       
        for (auto& [num, count] : subarray_count) {
            if (count == 1) {
                result = std::max(result, num);
            }
        }

        return result;

    }
};