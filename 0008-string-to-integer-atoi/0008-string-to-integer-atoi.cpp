class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sign = 1;
        int idx = 0;
        int len = s.size();
        while (s[idx] == ' ') {
            idx++;
        }
        if (s[idx] == '-') {
            sign = -1;
            idx++;
        } else if (s[idx] == '+') {
            idx++;
        }
        while (idx < len) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                num = 10 * num + s[idx] - '0';
                idx++;
                if (num * sign > INT_MAX) {
                    return INT_MAX;
                } else if (num * sign < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                break;
            }
        }
        
        return num * sign;
    }
};