class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings to hold characters for each row
        vector<string> rows(numRows);
        
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // Reverse direction at top or bottom boundaries
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
       string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};