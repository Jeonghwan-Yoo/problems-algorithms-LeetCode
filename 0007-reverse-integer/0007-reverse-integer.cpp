class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int num = x % 10;
            x /= 10;
            if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && num > 7) {
                return 0;
            }
            if (ret < INT_MIN / 10 || ret == INT_MIN / 10 && num < -8) {
                return 0;
            }
            ret = 10 * ret + num;
        }
        return ret;
    }
};