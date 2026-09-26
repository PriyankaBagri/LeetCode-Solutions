class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(const auto&pair:knowledge)
        {
            mp[pair[0]]=pair[1];
        }
        string key="";
        string res="";
        bool inside=false;
        for(char c:s)
        {
            if(c=='('){
            inside=true;}
            else if(c==')')
            {
                inside=false;
                auto it=mp.find(key);
                if(it!=mp.end())
                res+=it->second;
                else
                res+='?';
                key.clear();
            }
            else {
                if (inside) {
                    key += c;
                } else {
                    res += c;
                }
        }
    }
    return res;
    }
};