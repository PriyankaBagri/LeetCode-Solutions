class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();
        vector<int> count(26,0);
        for(char c: s)
        count[c- 'a']++;
        for(int i=n-1;i>=0;--i)
        {
            vector<int> freq=count;
            bool valid_prefix=true;
            for(int j=0;j<i;j++)
            {
                if (--freq[target[j] - 'a'] < 0) {
                    valid_prefix = false;
                    break;
                }
            }
            if(!valid_prefix)
            continue;
            for (int ch = target[i] - 'a' + 1; ch < 26; ++ch) {
                if (freq[ch] > 0) {
                    freq[ch]--;
                    string ans = target.substr(0, i);
                    ans += (char)('a' + ch);

                    // Append all remaining characters in sorted order
                    for (int c = 0; c < 26; ++c) {
                        while (freq[c] > 0) {
                            ans += (char)('a' + c);
                            freq[c]--;
                        }
                    }
                    return ans;
                }
            }
        }
        return "";
        }
    
};