class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, int, char>> arr(n);
        stack<tuple<int, int, int, char>> s;

        for (int i = 0; i < n; i++) {
            arr[i] = {positions[i], i, healths[i], directions[i]};
        }

        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++) {
            auto [currPos, originalPos, currHealth, currDir] = arr[i];
            
            while (!s.empty()) {
                auto [prevPos, j, prevHealth, prevDir] = s.top();
                if (prevDir == 'R' && currDir == 'L') {
                    if (prevHealth > currHealth) {
                        currHealth = 0;
                        s.pop();
                        s.push({prevPos, j, prevHealth - 1, prevDir});
                        break;
                    } else if (prevHealth < currHealth) {
                        currHealth--;
                        s.pop();
                    } else {
                        s.pop();
                        currHealth = 0;
                        break;
                    }
                } else {
                    break;
                }
            }
            
            if (currHealth > 0) {
                s.push({currPos, originalPos, currHealth, currDir});
            }
        }
        
        vector<pair<int, int>> survivors;
        while (!s.empty()) {
            auto [pos, origPos, health, dir] = s.top();
            s.pop();
            survivors.push_back({origPos, health});
        }

        sort(survivors.begin(), survivors.end());
        vector<int> result;
        for (auto &[index, health] : survivors) {
            result.push_back(health);
        }

        return result;
    }
};
