class Solution {
public:
    const int mod=1e9 +7;
    int solve(int i,int s,vector<int>& nums,vector<vector<int>>& dp){
        if(i>=nums.size()){
            return 1;
        }
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        int total=0;
        for(int ind=s;ind<=nums[i];ind++){
            int x=nums[i]-ind;
            if(i==0 || x<=nums[i-1]-s){
                total=(total%mod + solve(i+1,ind,nums,dp))%mod;
            }
        }
        return dp[i][s]=total;
    }
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(51,-1));
        return solve(0,0,nums,dp);
    }
};