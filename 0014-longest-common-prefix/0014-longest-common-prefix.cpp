class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        int minLen = strs[0].size();
        for (int i = 1; i < n; i++) {
            minLen = min(minLen, (int)strs[i].size());
        }
        
        int left = 0;
        int right = minLen;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isCommonPrefix(strs, mid)) {
                left++;
            } else {
                right--;
            }
        }
        int len = (left + right) / 2;
        return strs[0].substr(0, len);
    }
    
    bool isCommonPrefix(vector<string>& strs, int len) {
        int n = strs.size();
        
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < n; i++) {
            if (strs[i].find(prefix) != 0) {
                return false;
            }
        }
        return true;
    }
};