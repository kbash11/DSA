class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> arr(26,INT_MAX);
        string str=words[0];

        for(int i=0;i<str.size();i++){
            int ind=str[i]-'a';
            if(arr[ind]==INT_MAX){
                arr[ind]=1;
            }else{
                arr[ind]++;
            } 
        }

        for(int i=1;i<words.size();i++){
            unordered_map<char,int> m2;
            string s=words[i];
            for(int j=0;j<s.size();j++){
                m2[s[j]]++;
            }

            for(int j=0;j<26;j++){
                char ch='a'+j;
                if(m2.find(ch)!=m2.end() && arr[j]!=INT_MAX){
                    arr[j]=min(arr[j],m2[ch]);
                }else{
                    arr[j]=INT_MAX;
                }
            }
        }
        
        vector<string> ans;
        for(int i=0;i<26;i++){
            if(arr[i]!=INT_MAX){
                while(arr[i]!=0){
                    char ch='a'+i;
                    string s;
                    s+=ch;
                    ans.push_back(s);
                    arr[i]--;
                }
            }
        }
        return ans;
    }
};