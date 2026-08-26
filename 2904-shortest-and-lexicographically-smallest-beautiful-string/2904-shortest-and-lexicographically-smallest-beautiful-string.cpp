class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int left=0,ones=0,min=n+1;
        string res="";
        for(int right=0;right<n;right++)
        {
            if(s[right]=='1')
            ones++;
            while(ones==k)
            {
                while(s[left]=='0')
                left++;
            
            int curr=right-left+1;
            string sub=s.substr(left,curr);
            if(curr<min)
            {
            min=curr;
            res=sub;
            }
            else if(curr==min)
            {
                if(res>sub)
                res=sub;
            }
            left++;
            ones--;
        }
        }
        return res;
    }
};