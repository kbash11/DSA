class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int> rowDir = {0, -1, 0, 1};
            vector<int> colDir = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int nrow = row + rowDir[i];
                int ncol = col + colDir[i];

                if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};