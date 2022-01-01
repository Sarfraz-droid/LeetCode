class Solution {
public:

    int findMaxCounts(vector<int>& nums,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=j)
        {
            return 0;
        }
        
        int ans = INT_MIN;
        
        if(dp[i][j] != 0)
            return dp[i][j];
        
        for(int k = i;k<j;k++)
        {
            int tempans = findMaxCounts(nums,i,k,dp) + findMaxCounts(nums,k+1,j,dp) + nums[i-1]*nums[k]*nums[j];
            
            ans = max(tempans,ans);

        }
        
        return dp[i][j] = ans;
        
    }
    
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
                vector<vector<int>> dp(nums.size(),vector<int>(nums.size()));

        return findMaxCounts(nums,1,nums.size()-1,dp);
        
        
        
        
    }
};