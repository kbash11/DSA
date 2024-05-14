class Solution {
public: // T.C- O(M*N*(4^g))       S.C-O(m*n + g)
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row = {0, -1, 0, 1};
        vector<int> col = {-1, 0, 1, 0};
        int amount = 0;
        for (int i = 0; i < 4; i++) {
            int nrow = r + row[i];
            int ncol = c + col[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] != 0 && vis[nrow][ncol] == 0) {
                amount = max(amount, dfs(nrow, ncol, grid, vis));
            }
        }
        vis[r][c] = 0; // backtracking
        return amount + grid[r][c];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    maxi = max(maxi, dfs(i, j, grid, vis));
                }
            }
        }
        return maxi;
    }
};