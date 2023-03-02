class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        
        string newString = "#";
        for (int i = 0; i < len; i++) {
            newString += s[i];
            newString += "#";
        }
        
        int newStringLen = newString.size();
        vector<int> palindrome(newStringLen);
        int right = 0;
        int center = 0;
        int maxLen = 0;
        int maxCenter = 0;
        for (int i = 0; i < newStringLen; i++) {
            if (i < right) {
                palindrome[i] = min(right - i, palindrome[2 * center - i]);
            }
            while (i - palindrome[i] - 1 >= 0 && i + palindrome[i] + 1 < newStringLen 
                   && newString[i - palindrome[i] - 1] == newString[i + palindrome[i] + 1]) {
                palindrome[i]++;
            }
            if (i + palindrome[i] > right) {
                center = i;
                right = i + palindrome[i];
            }
            if (palindrome[i] > maxLen) {
                maxLen = palindrome[i];
                maxCenter = i;
            }
        }
        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};