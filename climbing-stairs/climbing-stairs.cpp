class Solution {
public:

    int calculate_stairs(int n,vector<int> &dp)
    {
        if(n <= 1)
            return 1;
        
        if(dp[n] != 0)
            return dp[n];
        
        return dp[n] = calculate_stairs(n-1,dp) + calculate_stairs(n-2,dp);
 
    }
        
    int climbStairs(int n) {
        vector<int> dp(n+1);
        
        return calculate_stairs(n,dp);
    }
};