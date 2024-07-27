
class Solution {
public:
    void solve(int src, vector<list<pair<int, int>>>& adj, vector<long long>& arr) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});
        arr[src] = 0; 

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto it : adj[node]) {
                if (dist + it.second < arr[it.first]) {
                    pq.push({dist + it.second, it.first});
                    arr[it.first] = dist + it.second;
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<list<pair<int, int>>> adj(26);    // O(1)
        for (int i = 0; i < original.size(); i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int w = cost[i];
            adj[u].push_back({v, w});
        }
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));    //O(1)

        for (int i = 0; i < 26; i++) {
            vector<long long> arr(26, LLONG_MAX);
            solve(i, adj, arr);
            dist[i] = arr; 
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == LLONG_MAX) {
                return -1;
            }
            totalCost += dist[u][v];
        }

        return totalCost;
    }
};
