class Solution {
public:
    bool isPalindrome(int x) {
        string stringX = to_string(x);
        int len = stringX.size();
        int len2 = len / 2;
        for (int i = 0; i < len2; i++) {
            if (stringX[i] != stringX[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};