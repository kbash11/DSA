class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        auto lambda=[&freq](int a,int b){
            if(freq[a]!=freq[b]){
                return freq[a]<freq[b];
            }
            return a>b;
        };
        sort(nums.begin(),nums.end(),lambda);

        return nums;
    }
};