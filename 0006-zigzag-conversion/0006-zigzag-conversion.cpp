class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int len = s.size();
        int rowIdx = 0;
        int sectionLen = 2 * (numRows - 1);
        string ret = "";
        for (int row = 0; row < numRows; row++) {
            int idx = row;
            while (idx < len) {
                ret += s[idx];
                idx += sectionLen;
                if (row != 0 && row != numRows - 1) {
                    idx -= 2 * row;
                    if (idx < len) {
                        ret += s[idx];
                    }
                    idx += 2 * row;
                }
            }
            
        }
        return ret;
    }
};