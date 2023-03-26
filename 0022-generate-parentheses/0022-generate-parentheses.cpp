class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        
        if (n == 0) {
            ret.emplace_back("");
            return ret;
        } 
        for (int i = 0; i < n; i++) {
            for (string left: generateParenthesis(i)) {
                for (string right: generateParenthesis(n - 1 - i)) {
                    ret.emplace_back("(" + left + ")" + right);
                }
            }
        }
        
        return ret;
    }
};