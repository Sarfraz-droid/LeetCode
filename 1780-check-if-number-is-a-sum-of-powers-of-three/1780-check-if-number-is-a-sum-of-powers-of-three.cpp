class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i = 16;i>=0;i--){
            if(n == 0)
                return true;
            int count = pow(3,i);
            if(count > n)
                continue;
            else
                n -= count;
        }
        
        return n == 0;
    }
};