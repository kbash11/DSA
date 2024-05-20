class Solution {
public:
    // int recursion(vector<int>& nums,int i,int x){
    //     if(i>=nums.size()){
    //         return x;
    //     }
    //     int exclude=recursion(nums,i+1,x);
    //     int include=recursion(nums,i+1,x^nums[i]);
    //     return include+exclude;
    // }
    int subsetXORSum(vector<int>& nums) {    
        // int sum=0;
        // int x=0;
        // return recursion(nums,0,x);         // T.C- O(2^N)    S.C-O(N)

        int ans=0;
        for(auto it:nums){
            ans |=it;
        }
        return ans << (nums.size()-1);
        
    }
};