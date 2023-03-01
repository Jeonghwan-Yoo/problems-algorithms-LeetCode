class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        
        int palindromeLen[1001][1001] = { 0, };
        for (int i = 0; i < len; i++) {
            palindromeLen[i][i] = 1;
        }
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                palindromeLen[i][i + 1] = 2;
            }
        }
        for (int sz = 3; sz <= len; sz++) {
            for (int start = 0; start < len - sz + 1; start++) {
                int end = start + sz - 1;
                if (s[start] == s[end] && palindromeLen[start + 1][end - 1] > 0) {
                    palindromeLen[start][end] = palindromeLen[start + 1][end - 1] + 2;
                }
            }
        }
        
        int maxLen = 0;
        string ret = "";
        for (int start = 0; start < len; start++) {
            for (int end = 0; end < len; end++) {
                if (palindromeLen[start][end] > maxLen) {
                    ret = s.substr(start, palindromeLen[start][end]);
                    maxLen = palindromeLen[start][end];
                }
            }
        }
        
        return ret;
    }
};