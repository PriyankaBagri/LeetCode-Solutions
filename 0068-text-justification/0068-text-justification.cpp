class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            // Find words for the current line
            int lineLength = words[i].length();
            int j = i + 1;
            
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length(); // 1 accounts for minimum space
                j++;
            }
            
            int wordCount = j - i;
            string line = "";
            
            // Case 1: Last line or line contains only one word -> Left Justified
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                // Pad remaining space on the right
                line += std::string(maxWidth - line.length(), ' ');
            } 
            // Case 2: Fully Justified
            else {
                // Total length of letters without any spaces
                int totalLetters = 0;
                for (int k = i; k < j; ++k) {
                    totalLetters += words[k].length();
                }
                
                int totalSpaces = maxWidth - totalLetters;
                int gaps = wordCount - 1;
                
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        // Distribute base spaces + 1 extra space to the leftmost gaps
                        int spacesToApply = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line += std::string(spacesToApply, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j; // Move to next line's starting word
        }
        
        return result;
    }
};