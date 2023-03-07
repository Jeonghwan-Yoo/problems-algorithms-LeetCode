class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbols = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        
        int n = s.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && symbols[s[i]] < symbols[s[i + 1]]) {
                ret -= symbols[s[i]];
            } else {
                ret += symbols[s[i]];
            }
        }
        
        return ret;
    }
};