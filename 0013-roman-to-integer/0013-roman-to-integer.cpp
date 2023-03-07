class Solution {
public:
    int romanToInt(string s) {
        const string symbols[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        const int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        
        int ret = 0;
        int n = s.size();
        int sIdx = 0;
        int symbolIdx = 0;
        while (sIdx < n) {
            if (symbolIdx % 2 == 1) {
                if (symbols[symbolIdx][0] == s[sIdx] && symbols[symbolIdx][1] == s[sIdx + 1]) {
                    ret += values[symbolIdx];
                    sIdx += 2;
                }
                symbolIdx++;
            } else {
                while (symbols[symbolIdx][0] == s[sIdx]) {
                    ret += values[symbolIdx];
                    sIdx++;
                }
                symbolIdx++;
            }
            
        }
        
        return ret;
    }
};