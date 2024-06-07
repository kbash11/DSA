class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string str="";
        map<string,int> m;
        for(auto it:dictionary){
            m[it]++;
        }
        int i=0;
        int n=sentence.size();
        while(i<n){
            string s="";
            string s2="";
            while(sentence[i]!=' ' && i<n){
                s+=sentence[i];
                if(m.find(s)!=m.end() && s2.empty()){
                    s2=s;
                }
                i++;
            }
            if(!s2.empty()){
                str+=s2+" ";
            }else{
                str+=s+" ";
            }
            i++;
        }
        if (!str.empty() && str.back() == ' ') {
            str.pop_back();
        }
        return str;
    }
};