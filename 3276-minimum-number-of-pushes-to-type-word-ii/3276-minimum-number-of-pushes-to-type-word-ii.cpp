class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int ans=0;
        int charCount=0;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                ans+=freq[i]*(charCount/8 + 1);
                charCount++;
            }
        }
        return ans;
    }
};