class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n=s.length();
        int max_length=0,length=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
            st.push(i);
            }
            else
            {
            st.pop();
          

        }
        if(st.empty())
        {
            st.push(i);
        }
        else
        {
            length=st.top();
            max_length=max(max_length,i-st.top());
        }
       
    }
    return max_length;
    }
};