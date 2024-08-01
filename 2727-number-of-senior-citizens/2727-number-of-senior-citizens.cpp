class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            string s=details[i];
            string age=s.substr(11,2);
            int a=stoi(age);
            if(a>60){
                count++;
            }
        }
        return count;
    }
};