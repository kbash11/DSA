class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // vector<vector<int>> ans(rowSum.size(),vector<int>(colSum.size(),0));         // T.C-O(n*m)   S.C-O(1)
        // for(int i=0;i<rowSum.size();i++){
        //     for(int j=0;j<colSum.size();j++){
        //         ans[i][j]=min(rowSum[i],colSum[j]);
        //         rowSum[i]-=ans[i][j];
        //         colSum[j]-=ans[i][j];
        //     }
        // }
        // return ans;

        vector<vector<int>> ans(rowSum.size(),vector<int>(colSum.size(),0));    //T.C-O(min(n,m))

        int i=0,j=0;
        while(i<rowSum.size() && j<colSum.size()){
            ans[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=ans[i][j];
            colSum[j]-=ans[i][j];
            if(rowSum[i]==0){
                i++;
            }else{
                j++;
            }
        }
        
        return ans;
    }
};