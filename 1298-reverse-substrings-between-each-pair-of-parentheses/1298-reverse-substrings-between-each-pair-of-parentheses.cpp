class Solution {
public:
    string reverseParentheses(string s) {

        unordered_map<int, int> m; // To store the index of closing and corresponding opening brackets
        stack<int> stk;

        // Fill the map with corresponding parentheses indices
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int openIndex = stk.top();
                stk.pop();
                m[openIndex] = i;
                m[i] = openIndex;
            }
        }
        int flag=1;
        string ans;
        for(int i=0;i<s.size();i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=m[i];
                flag=-flag;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;

        // stack<string> st;                        T.C-O(n)
        // int i = 0;

        // while (i < s.size()) {
        //     if (s[i] != ')') {
        //         string str(1, s[i]);
        //         st.push(str);
        //         i++;
        //     } else {
        //         string str = "";
        //         while (!st.empty() && st.top() != "(") {
        //             str = st.top() + str;
        //             st.pop();
        //         }
        //         if (!st.empty()) {
        //             st.pop();
        //         }
        //         reverse(str.begin(), str.end());
        //         st.push(str);
        //         i++;
        //     }
        // }

        // string result = "";
        // while (!st.empty()) {
        //     result = st.top() + result;
        //     st.pop();
        // }

        // return result;
    }
};