class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string ans;
        int l=0,r=0;
        while(l<n&&r<m)
        {
            ans+=word1[l];
            l++;
            ans+=word2[r];
            r++;
            if(l==n)
            {
            ans=ans+word2.substr(r,m);
            break;
            }
            if(r==m)
            {
            ans=ans+word1.substr(l,n);
            break;}
        }
        return ans;  
          }
};