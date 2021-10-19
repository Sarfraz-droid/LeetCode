class Solution {
public:
    vector<int> dp;
    
    int helper(int n)
    {
        if(n == 1)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        for(int i = 1;i<n;i++)
        {
            if(n%i == 0)
            {
                if(helper(n-1) == 0)
                    return dp[n] = 1;
            }
        }
        
        return dp[n] = 0;
    }
    
    bool divisorGame(int n) {
        dp.resize(n+1);
        
        fill(dp.begin(),dp.end(),-1);
        
        return helper(n);
        
    }
};