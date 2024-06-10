class Solution {
public:
    int heightChecker(vector<int>& heights) {

        unordered_map<int,int> m;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            mini=min(mini,heights[i]);
            maxi=max(maxi,heights[i]);
            m[heights[i]]++;
        }
        int ind=0;
        vector<int> sortedArr(heights.size());
        for(int val=mini;val<=maxi;val++){
            while(m[val]>0){
                sortedArr[ind]=val;
                ind++;
                m[val]--;
            }
        }
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(sortedArr[i]!=heights[i]){
                count++;
            }
        }
        return count;

        // vector<int> arr=heights;
        // sort(arr.begin(),arr.end());
        // int count=0;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]!=heights[i]){
        //         count++;
        //     }
        // }
        // return count;


        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(auto it:heights){
        //     pq.push(it);
        // }
        // int count=0;
        // for(int i=0;i<heights.size();i++){
        //     if(pq.top()!=heights[i]){
        //         count++;
        //     }
        //     pq.pop();
        // }
        // return count;
    }
};