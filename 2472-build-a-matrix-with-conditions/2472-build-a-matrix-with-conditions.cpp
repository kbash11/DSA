class Solution {
public:
    int K = 0;

    bool dfs(int node, vector<list<int>>& adj, vector<int>& vis, stack<int>& s) {
        vis[node] = 2;
        // stackFlag[node] = 1;
        
        for (auto it : adj[node]) {
            if (vis[it]==0 && dfs(it, adj, vis, s)) {
                vis[it]=2;
                return true;
            } else if (vis[it]==2) {
                return true;
            }
        }
        
        vis[node] = 1;
        s.push(node);
        return false;
    }

    vector<int> topoSort(vector<list<int>> adj) {
        vector<int> vis(K+1, 0);       // for visited vis = 1, same Path vis=2, unvisited vis=0
        // vector<int> stackFlag(K+1, 0); // To detect cycles
        stack<int> s;
        vector<int> ans;

        for (int i = 1; i <= K; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, s)) {
                    return {}; // Cycle detected, return empty vector
                }
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        K = k;
        vector<vector<int>> ans(k, vector<int>(k, 0));

        vector<list<int>> adjRow(k+1);
        vector<list<int>> adjCol(k+1);
        for (int i = 0; i < rowConditions.size(); i++) {
            adjRow[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for (int j = 0; j < colConditions.size(); j++) {
            adjCol[colConditions[j][0]].push_back(colConditions[j][1]);
        }

        vector<int> rowTopo = topoSort(adjRow);
        if (rowTopo.size() != k) {
            return {}; // Cycle detected in row conditions
        }

        vector<int> colTopo = topoSort(adjCol);
        if (colTopo.size() != k) {
            return {}; // Cycle detected in col conditions
        }

        for (int i = 0; i < k; i++) {
            auto x = find(colTopo.begin(), colTopo.end(), rowTopo[i]);
            if (x != colTopo.end()) {
                int col = distance(colTopo.begin(), x);
                ans[i][col] = rowTopo[i];
            }
        }

        return ans;
    }
};
