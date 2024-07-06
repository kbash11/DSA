class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 1, i = 1;
        while (time > 0) {
            if (i == n) {
                dir = -1;
            } else if (i == 1) {
                dir = 1;
            }
            i += dir;
            time--;
        }
        return i;
    }
};
