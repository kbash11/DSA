class UnionFind {
public:
    vector<int> parent;
    int groups;

    UnionFind(int n) : parent(n), groups(n - 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    bool unionSets(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x == y) {
            return false;
        } else {
            parent[y] = x;
            --groups;
            return true;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int count = 0;

        for (const auto& edge : edges) {
            int type = edge[0], u = edge[1] - 1, v = edge[2] - 1;
            if (type == 3 && alice.unionSets(u, v) && bob.unionSets(u, v)) {
                ++count;
            }
        }
        for (const auto& edge : edges) {
            int type = edge[0], u = edge[1] - 1, v = edge[2] - 1;
            if ((type == 1 && alice.unionSets(u, v)) || (type == 2 && bob.unionSets(u, v))) {
                ++count;
            }
        }

        if (alice.groups == 0 && bob.groups == 0) {
            return edges.size() - count;
        } else {
            return -1;
        }
    }
};