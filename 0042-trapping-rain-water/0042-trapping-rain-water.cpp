class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,max_l=0,max_r=0;
        int total_w=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(max_l<height[l])
                max_l=height[l];
            
            else
            
                total_w += max_l - height[l];
            
            l++;
        }
        else
        {
            if(height[r]>=max_r)
            {
                max_r=height[r];
            }
            else
            {
                total_w += max_r - height[r];
            }
            r--;
        }
        }
        return total_w;
    }
};