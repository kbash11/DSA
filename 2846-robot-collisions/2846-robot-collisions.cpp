class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        vector<int> actualInd(n);
        for(int i=0;i<n;i++){              // positions=[3,5,2,6]
            actualInd[i]=i;                // 0,1,2,3
        }
        

        auto lambda=[&](int i,int j){
            if(pos[i]<pos[j]){
                return true;
            }
            return false;
        };
        sort(actualInd.begin(), actualInd.end(), lambda);   // 2,0,1,3
        
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            int curr = actualInd[i];
            while (!s.empty() && dir[s.top()] == 'R' && dir[curr] == 'L') {
                int top = s.top();
                if (h[top] > h[curr]) {
                    h[top]--;
                    h[curr] = 0;
                    break;
                } else if (h[top] < h[curr]) {
                    h[curr]--;
                    s.pop();
                } else {
                    h[top] = 0;
                    h[curr] = 0;
                    s.pop();
                    break;
                }
            }
            if (h[curr] > 0) {
                s.push(curr);
            }
        }
        
        vector<pair<int, int>> survivors;
        while (!s.empty()) {
            survivors.push_back({s.top(), h[s.top()]});
            s.pop();
        }
        sort(survivors.begin(), survivors.end());
        
        vector<int> result;
        for (auto& p : survivors) {
            result.push_back(p.second);
        }
        return result;

        // vector<tuple<int, int, int, char>> arr(n);
        // stack<tuple<int, int, int, char>> s;

        // for (int i = 0; i < n; i++) {
        //     arr[i] = {positions[i], i, healths[i], directions[i]};
        // }

        // sort(arr.begin(), arr.end());
        
        // for (int i = 0; i < n; i++) {
        //     auto [currPos, originalPos, currHealth, currDir] = arr[i];
            
        //     while (!s.empty()) {
        //         auto [prevPos, j, prevHealth, prevDir] = s.top();
        //         if (prevDir == 'R' && currDir == 'L') {
        //             s.pop();
        //             if (prevHealth > currHealth) {
        //                 currHealth = 0;
        //                 s.push({prevPos, j, prevHealth - 1, prevDir});
        //                 break;
        //             } else if (prevHealth < currHealth) {
        //                 currHealth--;
        //             } else {
        //                 currHealth = 0;
        //                 break;
        //             }
        //         } else {
        //             break;
        //         }
        //     }
            
        //     if (currHealth > 0) {
        //         s.push({currPos, originalPos, currHealth, currDir});
        //     }
        // }
        
        // vector<pair<int, int>> survivors;
        // while (!s.empty()) {
        //     auto [pos, origPos, health, dir] = s.top();
        //     s.pop();
        //     survivors.push_back({origPos, health});
        // }

        // sort(survivors.begin(), survivors.end());
        // vector<int> result;
        // for (auto &[index, health] : survivors) {
        //     result.push_back(health);
        // }

        // return result;
    }
};
