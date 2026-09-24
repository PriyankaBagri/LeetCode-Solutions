class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int s=0,y=0;
        for(int i=0;i<n;i++)
        {
            int m=nums[i];
            s=0;
            while(m>0)
            {
                 y=m%10;
                 s=s+y;
                m=m/10;
            }
        
        if(s==i){
        return i;
       
        }
        }
        return -1;
    }
};