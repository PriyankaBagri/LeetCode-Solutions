class Solution {
public:
    vector<string> validStrings(int n) {
       vector<string> result;
       vector<string> st;
       st.push_back("");
       while(!st.empty()){
       string curr=st.back();
       st.pop_back();
       if(curr.length()==n)
       {
        result.push_back(curr);
        continue;
       }
       st.push_back(curr+"1");
       if (curr.empty() || curr.back() != '0') {
                st.push_back(curr + "0");
            }
        }

        return result;
    }
    
};