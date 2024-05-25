class Solution {
public:

    void solve(int i,string s,unordered_map<string,int> m,vector<string>& ans,string& str){
        if(i==s.size()){
            str.pop_back();                    // this is because of extra space generated in end 
            ans.push_back(str);
            return;
        }
        string s1="";
        for(int j=i;j<s.size();j++){
            s1+=s[j];
            if(m.find(s1)!=m.end()){
                string p=str;                     // make this string for backtracking
                str+=s1;
                str+=" ";
                solve(j+1,s,m,ans,str);
                str=p;                           // backtrack
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int> m;
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]=1;
        }
        vector<string> ans;
        string str="";
        solve(0,s,m,ans,str);
        return ans;
    }
};