class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal=0;string ans="";
        for(char c:s)
        {
            if(c=='(')
            {

                if(bal>0)
                ans+='(';
               bal++;
            }
            if(c==')')
            {
                bal--;
                if(bal>0)
                ans+=')';
            }
        }
        return ans;
    }
};