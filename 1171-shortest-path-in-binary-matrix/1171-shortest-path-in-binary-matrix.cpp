class Solution {
public:
    // int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
    //     int n=grid.size();
    //     int mini=INT_MAX;
    //     if(row==n-1 && col==n-1){
    //         return 1;
    //     }
    //     vis[row][col]=1;
    //     int path=INT_MAX;
    //     vector<int> r={0,-1,-1,-1,0,1,1,-1};
    //     vector<int> c={-1,-1,0,1,1,1,0,1};
    //     for(int i=0;i<8;i++){
    //         int nrow=row+r[i];
    //         int ncol=col+c[i];
    //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]!=1 && vis[nrow][ncol]!=1){
    //             int path = dfs(nrow, ncol, grid, vis);
    //             if (path != INT_MAX) {
    //                 mini = min(mini, path + 1);
    //             }
    //         }
    //     }
    //     vis[row][col]=0; // backtrack
    //     return mini;
    // }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;  // Start or end is blocked.
        }

        queue<tuple<int, int, int>> q;  // {row, col, distance}
        q.push({0, 0, 1});
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        grid[0][0] = 1;  // Mark the start cell as visited.

        while (!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();

            if (row == n-1 && col == n-1) {
                return dist;
            }

            for (auto& dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                    q.push({nrow, ncol, dist + 1});
                    grid[nrow][ncol] = 1;  // Mark the cell as visited.
                }
            }
        }

        return -1;  // No path found.
    }
};