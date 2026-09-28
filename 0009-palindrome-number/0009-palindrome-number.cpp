class Solution {
public:
    bool isPalindrome(int x) {
        long long s=0,m=x;
        while(x>0)
        {
            int r=x%10;
            s=s*10+r;
            x=x/10;
        }
        if(m==s)
        return true;
        else
        return false; 
    }
};