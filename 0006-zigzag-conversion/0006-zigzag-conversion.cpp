#define MAX_N 1'001

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int len = s.size();
        char board[MAX_N][MAX_N] = { NULL, };
        int curX = 0;
        int curY = 0;
        int direction = 0;
        for (int i = 0; i < len; i++) {
            board[curY][curX] = s[i];
            if (direction == 0) {
                if (curY == numRows - 1) {
                    direction = 1;
                    curX += 1;
                    curY -= 1;
                } else {
                    curY += 1;
                }
            } else {
                if (curY == 0) {
                    direction = 0;
                    curY += 1;
                } else {
                    curX += 1;
                    curY -= 1;
                }
            }
        }

        string ret = "";
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                if (board[i][j] != NULL) {
                    ret += board[i][j]; 
                }
            }
        }
        return ret;
    }
};