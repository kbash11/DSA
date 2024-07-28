class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<list<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> minTime1(n+1,INT_MAX);
        vector<int> minTime2(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});       // time=0, node=1
        minTime1[1]=0;
        
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            if(node==n && minTime2[node]!=INT_MAX){
                return minTime2[node];
            }
            int div=t/change;
            if(div%2!=0){
                t=(div+1)*change;
            }
            for(auto it:adj[node]){
                if(minTime1[it]>t+time){
                    minTime2[it]=minTime1[it];
                    minTime1[it]=t+time;
                    pq.push({t+time,it});
                }else if(minTime2[it]>t+time && minTime1[it]!=t+time ){
                    minTime2[it]=t+time;
                    pq.push({t+time,it});
                }
                
            }
        }
        return 0;
    }
};