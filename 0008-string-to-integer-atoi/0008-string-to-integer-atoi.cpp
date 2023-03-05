class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int sign = 1;
        int idx = 0;
        int len = s.size();
        
        while (idx < len && s[idx] == ' ') {
            idx++;
        }
        
        if (s[idx] == '-') {
            sign = -1;
            idx++;
        } else if (s[idx] == '+') {
            idx++;
        }
        
        int intMax10 = INT_MAX / 10;
        while (idx < len && s[idx] >= '0' && s[idx] <= '9') {
            if (num > intMax10 || (num == intMax10 && s[idx] > '7')) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            num = 10 * num + (s[idx] - '0');
            idx++;
        }
        
        return num * sign;
    }
};