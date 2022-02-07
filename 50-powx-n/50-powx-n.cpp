class Solution {
public:
    double myPow(double x, int num) {
        double ans = 1;
        bool flag = false;
        long long n = num;
        if(n<0){
            flag = true;
            n = -n;
        }
        
        while(n){
            
            if(n&1){
                ans*=x;
            }
            
            x*=x;
            n=n/2;
        }
        
        return flag ?  1/ans : ans;
    }
};