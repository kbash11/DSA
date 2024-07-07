class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles=0;
        int fullBottles=numBottles;
        int ans=numBottles;
        while(fullBottles/numExchange!=0){
            emptyBottles=fullBottles%numExchange;
            fullBottles=fullBottles/numExchange;
            ans+=fullBottles;
            fullBottles+=emptyBottles;
        }
        return ans;
    }
};