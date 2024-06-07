class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string str="";
        map<string,int> m;
        for(auto it:dictionary){               // O(d)
            m[it]++;
        }
        int i=0;
        int n=sentence.size();
        while(i<n){                          // O(n)
            string s="";
            string s2="";
            while(sentence[i]!=' ' && i<n){        // O(d)
                s+=sentence[i];
                if(m.find(s)!=m.end() && s2.empty()){                // O(log n)
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
        str.pop_back();
        return str;
    }
};