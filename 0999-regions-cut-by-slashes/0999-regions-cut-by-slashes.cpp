class Solution {
public:

    void dfs(vector<vector<int>> &matrix,int i,int j){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() ||matrix[i][j]==1){
            return;
        }
        matrix[i][j]=1;
        dfs(matrix,i-1,j);
        dfs(matrix,i,j+1);
        dfs(matrix,i+1,j);
        dfs(matrix,i,j-1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> matrix(n*3,vector<int>(m*3,0));

        int region=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    dfs(matrix,i,j);
                    region++;
                }
            }
        }
        return region;
    }
};