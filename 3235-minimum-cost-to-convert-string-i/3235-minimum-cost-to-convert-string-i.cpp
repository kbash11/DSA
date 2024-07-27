
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

    vector<vector<long long>> findShortestPath(vector<vector<int>>& graph) {
        vector<list<pair<int, int>>> adj(26); 
        for (int i = 0; i < graph.size(); i++) {
            int u = graph[i][0];
            int v = graph[i][1];
            int w = graph[i][2];
            adj[u].push_back({v, w});
        }
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX)); 

        for (int i = 0; i < 26; i++) {
            vector<long long> arr(26, LLONG_MAX);
            solve(i, adj, arr);
            dist[i] = arr; 
        }
        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> graph(original.size(), vector<int>(3));
        for (int i = 0; i < original.size(); i++) {
            graph[i][0] = original[i] - 'a';
            graph[i][1] = changed[i] - 'a';
            graph[i][2] = cost[i];
        }

        vector<vector<long long>> dist = findShortestPath(graph);

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
