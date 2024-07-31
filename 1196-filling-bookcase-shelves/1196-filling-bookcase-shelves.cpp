class Solution {
public:

    int solve(int i,int k,int maxHeight,vector<vector<int>>& books, int width,vector<vector<int>>& dp ){
        int n=books.size();
        if(i==n){
            return maxHeight;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }

        int exclude=maxHeight+solve(i+1,books[i][0],books[i][1],books,width,dp);

        int include=INT_MAX;
        if(k+books[i][0]<=width){
            include=solve(i+1,k+books[i][0],max(maxHeight,books[i][1]),books,width,dp);
        }
        return dp[i][k]=min(exclude,include);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>> dp(n,vector<int>(shelfWidth+1,-1));
        return solve(0,0,0,books,shelfWidth,dp);
    }
};