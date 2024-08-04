class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            auto it1 = s.lower_bound(u+1);
            auto it2 = s.upper_bound(v-1);
            s.erase(it1,it2);
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};