class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;

        // unordered_map<int,int> m;           // T.C-O(M+N)   S.C-O(M)
        // for(auto it:nums1){
        //     m[it]++;
        // }
        // vector<int> ans;
        // for(int i=0;i<nums2.size();i++){
        //     if(m[nums2[i]]>0){
        //         ans.push_back(nums2[i]);
        //         m[nums2[i]]--;
        //     }
        // }
        // return ans;
    }
};