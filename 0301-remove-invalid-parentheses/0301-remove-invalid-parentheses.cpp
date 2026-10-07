class Solution {
public:
   set<string> ans; 
   void solve(string &s, int i, string cur, int bal, int lr, int rr)
    { if(bal < 0 || lr < 0 || rr < 0) return; if(i == s.size()) { if(bal == 0 && lr == 0 && rr == 0) ans.insert(cur); return; } if(s[i] != '(' && s[i] != ')')
     { solve(s, i + 1, cur + s[i], bal, lr, rr); return; }
      if(s[i] == '(') { 
        solve(s, i + 1, cur + s[i], bal + 1, lr, rr);
       if(lr > 0)
        solve(s, i + 1, cur, bal, lr - 1, rr); } else { if(bal > 0) solve(s, i + 1, cur + s[i], bal - 1, lr, rr); if(rr > 0) solve(s, i + 1, cur, bal, lr, rr - 1); } } 
        
        
        
        vector<string> removeInvalidParentheses(string s) { 
            int lr = 0, rr = 0;
             for(char c : s)
              { if(c == '(')
               lr++; else if(c == ')') { if(lr > 0) lr--; else rr++; } } solve(s, 0, "", 0, lr, rr); return vector<string>(ans.begin(), ans.end()); } };