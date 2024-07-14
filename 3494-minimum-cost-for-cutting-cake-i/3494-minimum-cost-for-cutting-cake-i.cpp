

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x=horizontalCut.size(),y=verticalCut.size();
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        int hCut=1;
        int vCut=1;
        int i=0,j=0;
        int ans=0;
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
