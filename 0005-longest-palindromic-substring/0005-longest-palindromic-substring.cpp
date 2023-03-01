class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        
        int start = 0;
        int end = 0;
        for (int i = 0; i < len; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int biggerLen = max(len1, len2);
            if (biggerLen > end - start + 1) {
                start = i - ((biggerLen - 1) / 2);
                end = i + (biggerLen / 2);
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int expandAroundCenter(string s, int left, int right) {
        int len = s.size();
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};