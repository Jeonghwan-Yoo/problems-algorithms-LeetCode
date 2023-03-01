class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int ret = 0;
        
        vector<int> usedCharactersWithIndex(128, -1);
        int start = 0;
        for (int end = 0; end < len; end++) {
            char endVal = s[end];
            if (usedCharactersWithIndex[endVal] > 0) {
                start = max(start, usedCharactersWithIndex[endVal]);
            }
            ret = max(ret, end - start + 1);
            
            usedCharactersWithIndex[endVal] = end + 1;
        }

        return ret;
    }
};