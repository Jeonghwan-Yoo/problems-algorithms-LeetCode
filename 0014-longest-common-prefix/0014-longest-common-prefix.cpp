class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) {
            return strs[0];
        }
        
        int prefixIdx = 0;
        bool flag = true;
        string ret = "";
        while (flag) {
            for (int i = 0; i < n - 1; i++) {
                if (prefixIdx >= strs[i].size() || prefixIdx >= strs[i + 1].size()
                   || strs[i][prefixIdx] != strs[i + 1][prefixIdx]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                ret += strs[0][prefixIdx];
                prefixIdx++;
            }
        }
        
        return ret;
    }
};