class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int i = 0;

        while (i < s.size()) {
            if (s[i] != ')') {
                string str(1, s[i]);
                st.push(str);
                i++;
            } else {
                string str = "";
                while (!st.empty() && st.top() != "(") {
                    str = st.top() + str;
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
                reverse(str.begin(), str.end());
                st.push(str);
                i++;
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};