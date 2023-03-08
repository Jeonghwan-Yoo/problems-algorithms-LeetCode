class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
    string longestCommonPrefix(vector<string>& strs, int left, int right) {
        if (left == right) {
            return strs[left]; 
        }
        
        int mid = (left + right) / 2;
        string lcpLeft = longestCommonPrefix(strs, left, mid);
        string lcpRight = longestCommonPrefix(strs, mid + 1, right);
        
        return getCommonPrefix(lcpLeft, lcpRight);
    }
    
    string getCommonPrefix(string lcpLeft, string lcpRight) {
        int minLen = min(lcpLeft.size(), lcpRight.size());
        for (int i = 0; i < minLen; i++) {
            if (lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0, i);
            }
        }
        return lcpLeft.substr(0, minLen);
    }
};