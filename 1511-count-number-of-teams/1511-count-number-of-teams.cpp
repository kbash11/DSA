class Solution {
public:
    // int decr(int i,int prev,int k,vector<int>& arr,vector<vector<vector<int>>>& dp2){
        
    //     if(k==3){
    //         return 1;
    //     }
    //     if(i==arr.size()){
    //         return 0;
    //     }
    //     if(dp2[i][prev+1][k]!=-1){
    //         return dp2[i][prev+1][k];
    //     }
        
    //     int exclude=decr(i+1,prev,k,arr,dp2);
    //     int include=0;
    //     if(prev==-1 || arr[i]<arr[prev]){
    //         include=decr(i+1,i,k+1,arr,dp2);
    //     }
    //     return dp2[i][prev+1][k]=include+exclude;
    // }
    // int incre(int i,int prev,int k,vector<int>& arr,vector<vector<vector<int>>>& dp1){
    //     int n=arr.size();
    //     if(k==3){
    //         return 1;
    //     }
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp1[i][prev+1][k]!=-1){
    //         return dp1[i][prev+1][k];
    //     }
    //     int exclude=0+incre(i+1,prev,k,arr,dp1);
    //     int include=0;
    //     if(prev==-1 || arr[i]>arr[prev]){
    //         include=incre(i+1,i,k+1,arr,dp1);
    //     }
    //     return dp1[i][prev+1][k]=include+exclude;
    // }
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        for(int i=1;i<=n-1;i++){
            int smallerLeft=0,largerLeft=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    smallerLeft++;
                }else{
                    largerLeft++;
                }
            }
            int smallerRight=0,largerRight=0;
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    smallerRight++;
                }else{
                    largerRight++;
                }
            }
            ans+=smallerRight*largerLeft + smallerLeft*largerRight;
        }
        return ans;
    }
};