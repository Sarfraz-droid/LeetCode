class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n-1;i++)
        {
            int lim = min(i+nums[i],n-1);
            for(int j=lim;j>i;j--)
            {
                if(dp[j]>dp[i]+1)dp[j]=dp[i]+1;
                else break;
            }
        }
        
        return dp[n-1];
    }

};