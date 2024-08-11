class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        vector<int> row={-1,0,1,0};
        vector<int> col={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+row[i];
            int ncol=c+col[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis);                
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int totalIslands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    totalIslands++;
                }
            }
        }
        // cout<<totalIslands;
        if(totalIslands==0 || totalIslands>1){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int islands=0;
                    for(int k=0;k<n;k++){
                        for(int l=0;l<m;l++){
                            if(grid[k][l]==1 && !vis[k][l]){
                                dfs(k,l,grid,vis);
                                islands++;
                            }
                        }
                    }
                    if(islands==2 || islands==0){
                        return 1;
                    }else if(islands==1){
                        grid[i][j]=1;
                    }
                    for(int l=0;l<n;l++){
                        for(int k=0;k<m;k++){
                            vis[l][k]=0;
                        }
                    }  
                }
            }
        }
        return 2;
    }
};