class DisjointSet{
    
    public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUlp(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUlp(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUlp(u);
        int ulp_v=findUlp(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdge=0;
        int connComp=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUlp(u)==ds.findUlp(v)){
                extraEdge++;
            }else{
                ds.unionByRank(u,v);
            }
        }
        for(int i=0;i<n;i++){
            if(ds.findUlp(i)==i){
                connComp++;
            }
        }
        if(extraEdge>=connComp-1){
            return connComp-1;
        }else{
            return -1;
        }
    }
};