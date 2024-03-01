class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, int color, vector<vector<int>>& image, int initial) {

        int n = image.size();
        int m = image[0].size();
        vis[row][col]=1;
        image[row][col]=color;
        vector<int> rd={0,-1,0,1};
        vector<int> cd={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nrow=row+rd[i];
            int ncol=col+cd[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==initial){
                dfs(nrow,ncol,vis,color,image,initial);
                
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
    
        int initial=image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        if (!vis[sr][sc]) {
            dfs(sr, sc, vis, color, image,initial);
        }
        return image;
    }
};