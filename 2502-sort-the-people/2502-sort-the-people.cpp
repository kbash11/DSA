class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // auto lambda = [&heights](int a, int b) {
        //     return heights[a] > heights[b];
        // };

        // sort(names.begin(),names.end(),lambda);
        vector<string> ans;
        vector<pair<int,int>> arr;
        for(int i=0;i<heights.size();i++){
            arr.push_back({heights[i],i});
        }
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        for(auto it:arr){
            ans.push_back(names[it.second]);
        }
        return ans;
    }
};