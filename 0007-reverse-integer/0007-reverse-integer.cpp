class Solution {
public:
    int reverse(int x) {
        long long ret = 0ll;
        while (x != 0) {
            int num = x % 10;
            x /= 10;
            ret = 10 * ret + num;
        }
        if (ret < INT_MIN || ret > INT_MAX) {
            return 0;
        }
        return ret;
    }
};