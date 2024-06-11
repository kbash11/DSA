class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [diff,row,col]=pq.top();
            pq.pop();
            if(row==n-1 && col==m-1){
                return diff;
            }
            vector<int> r={0,-1,0,1};
            vector<int> c={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newEff=max(diff,abs(heights[nrow][ncol]-heights[row][col]));
                    if(newEff<dist[nrow][ncol]){
                        dist[nrow][ncol]=newEff;
                        pq.push({newEff,nrow,ncol});
                    }
                }
            }
        }
        return 0;
    }
};