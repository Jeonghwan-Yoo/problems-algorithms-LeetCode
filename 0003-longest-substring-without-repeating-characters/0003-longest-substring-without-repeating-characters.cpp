class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int ret = 0;
        
        unordered_map<char, int> usedCharactersWithCount;
        int start = 0;
        for (int end = 0; end < len; end++) {
            char endVal = s[end];
            usedCharactersWithCount[endVal]++;
            while (usedCharactersWithCount[endVal] > 1) {
                char startVal = s[start];
                usedCharactersWithCount[startVal]--;
                start++;
            }
            ret = max(ret, end - start + 1);
        }

        return ret;
    }
};