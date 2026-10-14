class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)
        return "";
        string ans;
        ans.reserve(num);
        for(int i=0;i<num;i++)
        {
            int d=min(9,sum);
            ans.push_back('0'+d);
            sum=sum-d;
        }
        return ans;
    }
};