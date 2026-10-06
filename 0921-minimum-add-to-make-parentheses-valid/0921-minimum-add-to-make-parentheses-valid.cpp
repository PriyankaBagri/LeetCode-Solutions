class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0,ans=0;
        for(char c:s)
        {
            if(c=='(')
            bal++;
            if(c==')')
            bal--;
            if(bal<0)
            {
                ans++;
                bal=0;
            }
        }
            return ans+bal;
        
    }
};