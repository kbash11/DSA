class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;    //S.C-O(n)
        for(auto it:nums){  // O(nlog(n))
            pq.push(it);
        }
        
        for(int i=0;i<nums.size();i++){   // O(nlog(n))
            nums[i]=pq.top();
            pq.pop();
        }
        return nums;
    }
};