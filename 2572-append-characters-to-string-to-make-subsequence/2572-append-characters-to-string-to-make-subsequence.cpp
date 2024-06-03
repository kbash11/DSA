class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int maxLen=0;
        int len=0;
        while(i<s.size() && j<t.size()){
            
            if(s[i]==t[j]){
                j++;
                len++;
            } 
            maxLen=max(maxLen,len);
            i++;
        }
        return t.size()-maxLen;
    }
};