class Solution {
public:
    // // void dfs(int node,vector<list<int>>& revAdj,set<int>& s){
    // //     if(revAdj[node].size()==0){
    // //         return;
    // //     }
    // //     for(auto it:revAdj[node]){
    // //         s.insert(it);
    // //         dfs(it,revAdj,s);
    // //     }
    // // }
    // vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    //     vector<list<int>> revAdj(n);
    //     for(int i=0;i<edges.size();i++){
    //         revAdj[edges[i][1]].push_back(edges[i][0]);
    //     }
    //     queue<int> q;
    //     for(int i=0;i<n;i++){
    //         if(revAdj[i].size()==0){
    //             q.push(i);
    //         }
    //     }
    //     vector<int> topo(n);
    //     vector<vector<int>> ans(n);
    //     // for(int i=0;i<n;i++){
    //     //     set<int> s;
    //     //     dfs(i,revAdj,s);
            
    //     //     ans[i]=vector<int>(s.begin(),s.end());
    //     // }
        
        
        
    //     while(!q.empty()){

    //     }
    //     return ans;
        
    // }

void dfs(int node, vector<list<int>>& revAdj, vector<int>& arr, vector<bool>& visited) {
    visited[node] = true;
    for (auto it : revAdj[node]) {
        if (!visited[it]) {
            arr.push_back(it);
            dfs(it, revAdj, arr, visited);
        }
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<list<int>> revAdj(n);  // Initialize revAdj with n elements
    for (const auto& edge : edges) {
        revAdj[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> ans(n);  // Initialize ans with n elements
    for (int i = 0; i < n; ++i) {
        vector<int> arr;
        vector<bool> visited(n, false);  // Visited array to avoid revisiting nodes
        dfs(i, revAdj, arr, visited);
        sort(arr.begin(), arr.end());
        ans[i] = arr;
    }
    return ans;
}

};