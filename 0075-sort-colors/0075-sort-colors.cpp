class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        int low=0,high=nums.size()-1;
        int i=0;
        while(i<=high ){
            if(nums[i]==0){
                swap(nums[i],nums[low]);
                low++;
            }else if(nums[i]==2){
                swap(nums[i],nums[high]);
                high--;
                i--;
            }
            i++;
        }
    }
};