
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        unordered_map<int, int> m;
        for (auto it : hand) {
            m[it]++;
        }
        
        sort(hand.begin(), hand.end());
        
        for (int i = 0; i < hand.size(); i++) {
            if (m[hand[i]] == 0) {
                continue; // Skip if the card has already been used
            }
            
            for (int j = 0; j < groupSize; ++j) {
                if (m[hand[i] + j] == 0) {
                    return false; // If we can't form a consecutive group, return false
                }
                m[hand[i] + j]--; // Decrease the count of the card
            }
        }
        
        return true;
    }
};
