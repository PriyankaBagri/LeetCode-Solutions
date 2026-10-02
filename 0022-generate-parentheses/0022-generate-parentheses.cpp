class Solution {
public:
void backtrack(int open,int close,int n,string& curr,vector<string> &result)
{
    if(curr.length()==2*n)
    {
    result.push_back(curr);
    return;
    }
    if(open<n)
    {
        curr.push_back('(');
        backtrack(open+1,close,n,curr,result);
        curr.pop_back();
    }
    if(close<open)
    {
        curr.push_back(')');
        backtrack(open,close+1,n,curr,result);
        curr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr="";
        backtrack(0,0,n,curr,result);
        return result;
    }
};