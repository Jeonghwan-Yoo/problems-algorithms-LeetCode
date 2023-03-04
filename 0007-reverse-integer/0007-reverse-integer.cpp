class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        
        while (x % 10 == 0) {
            x /= 10;
        }
        string stringX = to_string(x);
        int offset = 0;
        if (stringX[0] == '-') {
            offset = 1;
        }
        std::reverse(stringX.begin() + offset, stringX.end());
        int ret = 0;
        try {
            ret = stoi(stringX);
        } catch (...) {
            ret = 0;
        }
        return ret;
    }
};