class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4){
            return 0;
        }
        // sort(nums.begin(),nums.end());          T.C-O(n)

        //sort starting 4 elements
        partial_sort(nums.begin(),nums.begin()+4,nums.end());      // O(nlog(4))   ~ O(n)

        //element at (n-4)th pos. if sorted
        nth_element(nums.begin()+4,nums.begin()+(n-4),nums.end());   //O(n)

        //sort last 4 elements
        sort(nums.begin()+(n-4),nums.end());                         // O(4log(4))  `O(1)

        int ans=INT_MAX;
        ans=min(ans,nums[n-4]-nums[0]);
        ans=min(ans,nums[n-3]-nums[1]);
        ans=min(ans,nums[n-2]-nums[2]);
        ans=min(ans,nums[n-1]-nums[3]);
    
        return ans;
    }
};