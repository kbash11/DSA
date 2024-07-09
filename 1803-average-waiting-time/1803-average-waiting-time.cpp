class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time=customers[0][0]+customers[0][1];
        double avgTime=customers[0][1];
        for(int i=1;i<customers.size();i++){
            if(customers[i][0]<time){
                time+=customers[i][1];
                avgTime+=time-customers[i][0];
            }else{
                time=customers[i][0]+customers[i][1];
                avgTime+=customers[i][1];
            }
        }
        return avgTime/customers.size();
    }
};