class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x=horizontalCut.size(),y=verticalCut.size();
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        long long hCut=1;
        long long vCut=1;
        int i=0,j=0;
        long long ans=0;
        while(i<x && j<y){
            if(horizontalCut[i]>verticalCut[j]){
                ans+=horizontalCut[i]*vCut;
                hCut++;
                i++;
            }else{
                ans+=verticalCut[j]*hCut;
                vCut++;
                j++;
            }
        }
        while(i<x){
            ans+=horizontalCut[i]*vCut;
            hCut++;
            i++;
        }
        while(j<y){
            ans+=verticalCut[j]*hCut;
            vCut++;
            j++;
        }
        return ans;
    }
};