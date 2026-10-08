class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n=s.size(),i=0;
        while (i < s.size()) {
        if (s[i] == '(') {
            if (st.empty()) {
                st.push(s[i]);
                s.erase(s.begin() + i);
            } else {
                st.push('(');
                ++i;
            }
        } else if (s[i] == ')') {
            if (st.size() == 1) {
                st.pop();
                s.erase(s.begin() + i);
            } else {
                st.pop();
                ++i;
            }
        } else {
            ++i;
        }
    }
    return s;
    }
};