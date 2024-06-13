class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<list<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        queue<pair<int, int>> q;
        q.push({0, k});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!q.empty()) {
            auto [time, node] = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (time + it.second < dist[it.first]) {
                    dist[it.first] = time + it.second;
                    q.push({dist[it.first], it.first});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(dist[i], ans);
        }
        return ans;
    }
};
