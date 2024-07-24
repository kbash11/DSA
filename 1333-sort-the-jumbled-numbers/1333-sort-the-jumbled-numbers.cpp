#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Create the mapping
        unordered_map<int, int> m;
        for (int i = 0; i < mapping.size(); i++) {
            m[i] = mapping[i];
        }

        // Convert nums based on the mapping
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            string temp = to_string(nums[i]);
            string s;
            for (int j = 0; j < temp.size(); j++) {
                int x = temp[j] - '0';
                s += to_string(m[x]);
            }
            int y = stoi(s);
            arr.push_back(y);
        }

        // Pair the transformed numbers with their original indices
        vector<pair<int, int>> arr2;
        for (int i = 0; i < arr.size(); i++) {
            arr2.push_back({arr[i], i});
        }

        // Sort based on the transformed numbers
        sort(arr2.begin(), arr2.end());

        // Create the result based on the sorted transformed numbers
        vector<int> ans;
        for (int i = 0; i < arr2.size(); i++) {
            int x = nums[arr2[i].second];
            ans.push_back(x);
        }

        return ans;
    }
};
