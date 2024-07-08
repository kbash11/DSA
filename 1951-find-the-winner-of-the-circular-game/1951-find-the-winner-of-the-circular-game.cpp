class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int i=1;
        while(i!=n+1){
            q.push(i);
            i++;
        }
        int j=1;
        while(q.size()!=1){
            int x=q.front();
            q.pop();
            if(j!=k){
                q.push(x);
            }else{
                j=0;
            }
            j++;
        }
        return q.front();
    }
};