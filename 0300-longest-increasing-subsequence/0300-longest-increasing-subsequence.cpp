class Solution {
public:
    int solve(int i,int prev,vector<int>& arr,vector<vector<int>>& dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int exclude=0+solve(i+1,prev,arr,dp);
        int include=0;
        if(prev==-1 || arr[i]>arr[prev]){
            include=1+solve(i+1,i,arr,dp);
        }
        return dp[i][prev+1]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};