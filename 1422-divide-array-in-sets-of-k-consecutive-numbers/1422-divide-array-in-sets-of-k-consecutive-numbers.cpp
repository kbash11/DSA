class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
        unordered_map<int, int> m;
        for (auto it : hand) {
            m[it]++;
        }
        
        sort(hand.begin(), hand.end());
        
        for (int i = 0; i < hand.size(); i++) {
            if (m[hand[i]] == 0) {
                continue;
            }
            
            for (int j = 0; j < k; ++j) {
                if (m[hand[i] + j] == 0) {
                    return false;
                }
                m[hand[i] + j]--;
            }
        }
        
        return true;
    }
};