class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // unordered_map<int,int> m;          // T.C - O(n)  S.C - O(n)
        // for(int i=0;i<edges.size();i++){
        //     m[edges[i][0]]++;
        //     m[edges[i][1]]++;
        // }
        // for(auto it:m){
        //     if(it.second>1){
        //         return it.first;
        //     }
        // }
        // return 0;
        auto it1 = edges[0];
        auto it2 =edges[1];
        if(it1[0]== it2[1] || it1[0]==it2[0]){
            return it1[0];
        }
        return it1[1];
    }
};