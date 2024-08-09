class Solution {
public:
    bool isMagic(int r,int c,vector<vector<int>>& grid){
        unordered_set<int> s;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(grid[i][j]<1 || grid[i][j]>9 || s.count(grid[i][j])){
                    return false;
                }else{
                    s.insert(grid[i][j]);
                }
            }
        }
        int rowSum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=r+1;i<r+3;i++){
            if(grid[i][c]+grid[i][c+1]+grid[i][c+2]!=rowSum ){
                return false;
            }
        }
        for(int j=c;j<c+3;j++){
            if(grid[r][j]+grid[r+1][j]+grid[r+2][j]!=rowSum ){
                return false;
            }
        }
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=rowSum || grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=rowSum){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n<3 || m<3){
            return 0;
        }
        int count=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(isMagic(i,j,grid)){
                    count++;
                }
            }
        }
        return count;
    }
};