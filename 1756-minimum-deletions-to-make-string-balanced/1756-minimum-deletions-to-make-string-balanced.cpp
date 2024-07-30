class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]=='a' && st.top()=='b'){
                st.pop();
                ans++;
            }else{
                st.push(s[i]);
            }
        }
        return ans;

        // int counta=0,countb=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='b'){
        //         countb++;
        //     }else{
        //         counta++;
        //     }
        // }
        // int ans=countb;
        // int preva=0;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,)
        // }
        // return ans;
    }
};