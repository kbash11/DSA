class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size=0;
        for(auto it:nums){
            if(it==1){
                size++;
            }
        }
        vector<int> arr=nums;
        for(int i=0;i<size;i++){
            arr.push_back(nums[i]);
        }

        int i=0,j=0;
        int count0=0,ans=INT_MAX;
        while(j<arr.size()){
            if(arr[j]==0){
                count0++;
            }
            if(j-i+1==size){
                ans=min(ans,count0);
                if(arr[i]==0){
                    count0--;
                }
                i++;
            }
            j++;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};