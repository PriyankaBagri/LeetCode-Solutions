class Solution {
public:
vector<vector<string>> ans;
vector<string> path;
bool isPalindrome(string &s,int left,int right)
{
    while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }


void solve(string &s,int start)
{
    if(start==s.length()){
    ans.push_back(path);
    return;
    }
    for(int end=start;end<=s.length();end++)
    {
        if(isPalindrome(s,start,end)){
        path.push_back(s.substr(start,end-start+1));
        solve(s,end+1);
        path.pop_back();
    }
    }
}
    vector<vector<string>> partition(string s) {
       solve(s,0);
       return ans; 
    }
};