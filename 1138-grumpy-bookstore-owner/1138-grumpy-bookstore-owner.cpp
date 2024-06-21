class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int unsat=0;
        for(int i=0;i<minutes;i++){
            unsat+=customers[i]*grumpy[i];
        }
        int maxi=unsat;
        int i=0,j=minutes;
        while(j<n){
            unsat+=customers[j]*grumpy[j];
            unsat-=customers[i]*grumpy[i];
            maxi=max(maxi,unsat);
            i++;
            j++;
        }
        int ans=maxi;
        for(int k=0;k<n;k++){
            if(grumpy[k]==0){
                ans+=customers[k];
            }
        }
        return ans;
    }
};