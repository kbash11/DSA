class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long s=0;
        long long e=sqrt(c);
        while(s<=e){
            long long sum=s*s+e*e;
            if(c<sum){
                e--;
            }else if(c>sum){
                s++;
            }else{
                return true;
            }
        }
        return false;
    }
};