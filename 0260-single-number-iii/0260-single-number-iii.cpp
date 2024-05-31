class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]++;
            if(m[it]==2){
                m.erase(it);
            }
        }
        vector<int> ans;
        for(auto i: m){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         // Step 1: Perform XOR of all numbers to get XOR of the two unique numbers
//         int XOR = 0;
//         for (int num : nums) {
//             XOR ^= num;
//         }

//         // Step 2: Find the rightmost set bit in XOR
//         // Instead of using ~ and - operations, we find the rightmost set bit directly
//         int bitmask = 1;
//         while ((XOR & bitmask) == 0) {
//             bitmask <<= 1;
//         }

//         // Step 3: Divide numbers into two groups based on the bit found and XOR within each group
//         int a = 0, b = 0;
//         for (int num : nums) {
//             if (num & bitmask) {
//                 a ^= num;
//             } else {
//                 b ^= num;
//             }
//         }

//         // Step 4: Return the two unique numbers
//         return {a, b};
//     }
// };
