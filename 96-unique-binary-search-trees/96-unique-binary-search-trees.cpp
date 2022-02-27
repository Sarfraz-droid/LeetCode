class Solution {
public:
    vector<int> dp;
    int catalan(int n){
        if(n <= 1)
            return 1;
        int res = 0;
        
        if(dp[n] != 0)
            return dp[n];
        
        for(int i = 0;i<=n-1;i++){
            res += catalan(i)*catalan(n-i-1);
        }
        
        return dp[n] = res;
    }
    
    int numTrees(int n) {
        dp.resize(100);
        return catalan(n);
    }
};