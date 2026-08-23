class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
    
    for (char c : s) {
        // If it's an opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            // If stack is empty or top element doesn't match
            if (st.empty()) return false;
            
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    
    // Valid only if all opened brackets were closed
    return st.empty();
    }
};