class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (s[i] == '[') {
                st.push(']');
            } else {
                if (st.empty() || st.top() != s[i]) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};