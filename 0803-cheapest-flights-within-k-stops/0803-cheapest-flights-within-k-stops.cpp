class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<list<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        // priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        queue<tuple<int,int,int>> q;
        q.push({0,src,0});
        vector<int> d(n,INT_MAX);
        d[src]=0;
        while(!q.empty()){
            auto [stops,node,dist]=q.front();
            q.pop();
            
            if(stops<=k){
                for(auto& it : adj[node]){
                    // it.first- new node
                    //it.second-dist
                    if(dist+it.second<d[it.first]){
                        d[it.first]=dist+it.second;
                        q.push({stops+1,it.first,dist+it.second});
                    }  
                }
            }
        }
        if(d[dst]==INT_MAX){
            return -1;
        }
        return d[dst];
    }
};