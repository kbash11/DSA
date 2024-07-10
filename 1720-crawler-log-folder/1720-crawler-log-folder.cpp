class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(int i=0;i<logs.size();i++){
            string s=logs[i];
            if(s=="./"){
                continue;
            }
            if(s=="../" ){
                if(ans!=0){
                    ans--;
                }  
            }else{
                ans++;
            }
        }
        // if(ans<0){
        //     return 0;
        // }
        return ans;
    }
};