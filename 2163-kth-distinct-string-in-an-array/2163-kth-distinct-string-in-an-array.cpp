class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        for(auto it:arr){
            m[it]++;
        }
        for(int i=0;i<arr.size();i++){
            string s=arr[i];
            if(m[s]==1){
                k--;
            }
            if(k==0){
                return s;
            }
        }
        return "";
    }
};