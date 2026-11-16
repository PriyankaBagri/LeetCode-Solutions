class Solution {
public:
    string digitSum(string s, int k) {
       while(s.length()>k)
       {
        string ans="";
        for(int i=0;i<s.length();i=i+k)
        {
            string sub=s.substr(i,k);
            int sum=0;
            for(int j=0;j<sub.length();j++)
            {
                sum=sum+sub[j]-'0';
            }
            ans=ans+to_string(sum);
        }
        s=ans;
       }
       return s; 
    }
};