class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0,j=0,n=arr.size();
        while(j<n){
            if(arr[j]%2==0){
                i=j+1;
                j++;
            }else{
                j++;
            }
            if(j-i==3){
                return true;
            }
        }
        return false;
    }
};