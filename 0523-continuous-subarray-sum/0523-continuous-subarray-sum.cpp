class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> preSum(nums.size());
        preSum[0]=nums[0]%k;
        for(int i=1;i<nums.size();i++){
            preSum[i]=(preSum[i-1]+nums[i])%k;
        }
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<preSum.size();i++){
            if(m.find(preSum[i])!=m.end()){
                if(i-m[preSum[i]]>=2){
                    return true;
                }
            }else{
                m[preSum[i]]=i;
            }
        }
        return false;
    }
};