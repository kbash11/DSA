class Solution {
public:
    int heightChecker(vector<int>& heights) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:heights){
            pq.push(it);
        }
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(pq.top()!=heights[i]){
                count++;
            }
            pq.pop();
        }
        return count;
    }
};