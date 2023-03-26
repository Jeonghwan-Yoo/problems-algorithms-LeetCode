class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        makeAllParenthesis(n, n, "", ret);
        
        return ret;
    }
    
    void makeAllParenthesis(int open, int close, string cur, vector<string>& parenthsis) {
        if (open == 0 && close == 0) {
            if (isValid(cur)) {
                parenthsis.emplace_back(cur);
            }
            return;
        }
        if (open > 0) {
           makeAllParenthesis(open - 1, close, cur + "(", parenthsis); 
        }
        if (close > 0) {
            makeAllParenthesis(open, close - 1, cur + ")", parenthsis);
        }
    }
    
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == ')') {
                if (st.empty() || c != st.top()) {
                    return false;
                }
                st.pop();
            } else if (c == '(') {
                st.push(')');
            }
        }
        return st.empty();
    }
};