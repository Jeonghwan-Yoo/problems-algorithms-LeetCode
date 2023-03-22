class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        
        function<void(int, int, string)> generate = [&](int open, int close, string cur) {
            if (open == 0 && close == 0) {
                ret.emplace_back(cur);
                return;
            }
            if (open > 0) {
                generate(open - 1, close, cur + "(");    
            }
            if (close > 0 && open < close) {
                generate(open, close - 1, cur + ")");    
            }
        };
        generate(n, n, "");
        
        return ret;
    }
};