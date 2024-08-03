class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto it: arr){
            m[it]++;
        }
        for(auto it:target){
            if(m[it]==0){
                return false;
            }
            m[it]--;
        }
        return true;
    }
};