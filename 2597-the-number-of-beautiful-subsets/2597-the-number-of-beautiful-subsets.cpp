class Solution {
public:
    int result=0;
    void recursion(int i,vector<int>& nums,unordered_map<int,int>& m,int k){
        
        if(i==nums.size()){
            result++;
            return ;
        }
    
        recursion(i+1,nums,m,k);    // exclude
        
        if(!m[nums[i]-k] && !m[nums[i]+k]){          // checking wether diff is present or not
            m[nums[i]]++;                            //add
            recursion(i+1,nums,m,k);                 //explore
            m[nums[i]]--;                            //remove

        }
    }
        
    int beautifulSubsets(vector<int>& nums, int k) {
        
        unordered_map<int,int> ans;

        recursion(0,nums,ans,k);
        return result-1;                        // one empty subset that's why -1
        
    }
};