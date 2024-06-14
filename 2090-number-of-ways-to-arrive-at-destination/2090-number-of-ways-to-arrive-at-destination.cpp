class Solution {
public:
    const int mod=1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<list<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long> time(n,LLONG_MAX),ways(n,0);
        time[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            
            for(auto it:adj[node]){
                if(it.second+t<time[it.first]){
                    time[it.first]=it.second+t;
                    pq.push({time[it.first],it.first});
                    ways[it.first]=ways[node];
                }else if(it.second+t==time[it.first]){
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};