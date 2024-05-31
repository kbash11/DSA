// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int> ans;
//         int XOR=0;
//         for(int i=0;i<nums.size();i++){
//             XOR=XOR^nums[i];
//         }
        
//         long long ind=0;
//         while(XOR%2!=1){
//             ind++;
//             XOR=XOR/2;
//         }

//         int a=0,b=0;
//         for(int i=0;i<nums.size();i++){
//             int check=nums[i];
//             long long index=0;
//             while(index!=ind){
//                 index++;
//                 check=check/2;
//             }

//             if(check%2==0){
//                 b=b^nums[i];
//             }else if(check%2==1){
//                 a=a^nums[i];
//             }
//         }
//         ans.push_back(a);
//         ans.push_back(b);
//         return ans;
//     }
// };

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: Perform XOR of all numbers to get XOR of the two unique numbers
        int XOR = 0;
        for (int num : nums) {
            XOR ^= num;
        }

        // Step 2: Find the rightmost set bit in XOR
        // Instead of using ~ and - operations, we find the rightmost set bit directly
        int bitmask = 1;
        while ((XOR & bitmask) == 0) {
            bitmask <<= 1;
        }

        // Step 3: Divide numbers into two groups based on the bit found and XOR within each group
        int a = 0, b = 0;
        for (int num : nums) {
            if (num & bitmask) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        // Step 4: Return the two unique numbers
        return {a, b};
    }
};
