class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        
        string prefix = strs[0];
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            for (int j = 0; j < n; j++) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return prefix.substr(0, i);
                }
            }
        }
        
        return prefix;
    }
};