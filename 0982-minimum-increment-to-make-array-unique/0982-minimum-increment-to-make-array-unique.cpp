class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // unordered_map<int,int> m;
        // int moves=0;
        // for(int i=0;i<nums.size();i++){
        //     if(m.find(nums[i])!=m.end()){
        //         int x=nums[i];
        //         while(m.find(x)!=m.end()){
        //             x+=1;
        //             moves+=1;
        //         }
        //         nums[i]=x;
        //     }
        //    m[nums[i]]++;
        // }
        // return moves; 
        sort(nums.begin(),nums.end());
        unordered_map<int,int> dict;
        
        int next=0;
        int moves=0;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(dict.find(curr)!=dict.end()){
                moves+=next-curr;
                curr=next;
                next+=1;
                dict[curr]++;
            }else{
                dict[curr]++;
                next=curr+1;
            }
        } 
        return moves;
    }
};