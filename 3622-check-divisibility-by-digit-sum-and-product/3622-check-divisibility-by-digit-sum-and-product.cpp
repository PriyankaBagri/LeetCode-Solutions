class Solution {
public:
    bool checkDivisibility(int n) {
        int m=n,r=0,s=0,p=1;
        while(n>0)
        {
             r=n%10;
             s=s+r;
             p=p*r;
            n=n/10;
        }
        if(m%(s+p)==0)
        return true;
        else
        return false;
    }
};