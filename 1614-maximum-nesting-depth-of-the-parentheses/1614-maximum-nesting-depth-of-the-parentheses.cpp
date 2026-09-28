class Solution {
public:
    int maxDepth(string s) {
        int b=0,maxb=0;
       for(char c:s)
       {
            if(c=='('){
            b++;
            maxb=max(maxb,b);
            }
            if(c==')')
            {
                b--;
            }
       }
       return maxb;
       } 
    
};