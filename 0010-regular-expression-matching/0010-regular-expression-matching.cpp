class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        
        function<bool(int, int)> findMatch = [&](int sIdx, int pIdx) {
            if (dp[sIdx][pIdx] != -1) {
                if (dp[sIdx][pIdx]) {
                    return true;
                }
                return false;
            }
            
            bool ret = false;
            if (pIdx >= p.size()) {
                ret = sIdx >= s.size();
            } else {
                bool firstMatch = (sIdx < s.size() && (s[sIdx] == p[pIdx] || p[pIdx] == '.'));
                if (pIdx + 1 < p.size() && p[pIdx + 1] == '*') {
                    ret = findMatch(sIdx, pIdx + 2) || (firstMatch && findMatch(sIdx + 1, pIdx));
                } else {
                    ret = firstMatch && findMatch(sIdx + 1, pIdx + 1);
                }
            }
            dp[sIdx][pIdx] = ret;
            
            return ret;
        };
        
        return findMatch(0, 0);
    }
};