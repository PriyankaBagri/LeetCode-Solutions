class Solution {

public:
set<string> multiply(set<string> a, set<string> b) {
        set<string> result;
        for (string s1 : a) {
            for (string s2 : b) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }
set<string> parse(string s)
 {
        set<string> union_set;
        set<string> product_set = {""};
        int i = 0;

        while (i < s.size()) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                string word = "";
                while (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
                    word += s[i];
                    i++;
                }
                set<string> single_word = {word};
                product_set = multiply(product_set, single_word);
            } 
            else if (s[i] == '{') {
                int start = i + 1;
                int brace_count = 1;
                i++;
                while (i < s.size() && brace_count > 0) {
                    if (s[i] == '{') brace_count++;
                    if (s[i] == '}') brace_count--;
                    i++;
                }
                string inner = s.substr(start, i - 1 - start);
                set<string> inner_result = parse(inner);
                product_set = multiply(product_set, inner_result);
            } 
            else if (s[i] == ',') {
                for (string word : product_set) {
                    union_set.insert(word);
                }
                product_set = {""};
                i++;
            }
        }

        for (string word : product_set) {
            union_set.insert(word);
        }

        return union_set;
    }
    vector<string> braceExpansionII(string expression) {
       set<string> res= parse(expression);
        vector<string> ans;
        for (string word : res) {
            ans.push_back(word);
        }
        return ans;
    }
};