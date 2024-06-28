class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> m;
        for(int i=0;i<roads.size();i++){
            m[roads[i][0]]++;
            m[roads[i][1]]++;
        }
        long long maxImp=0;
        priority_queue<long long> pq;
        for(auto it:m){
            pq.push(it.second);
        }
        while(!pq.empty()){
            maxImp+=pq.top()*n;
            pq.pop();
            n--;
        }
        return maxImp;
    }
};