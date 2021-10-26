class Solution {
public:
    
    bool find_partition(vector<int>& nums,int l,int r,int i,vector<vector<int>> &dp)
    {
                // cout<<l<<" "<<r<<" "<<i<<endl;

        if(i == nums.size())
            return l == r;
        
        if(dp[i][l] != -1)
            return dp[i][l];
    
        bool ans = find_partition(nums,l+nums[i],r,i+1,dp) or find_partition(nums,l,r+nums[i],i+1,dp);
        
        dp[i][l] = (int)ans;
        
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        
        // cout<<sum<<endl;
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1,-1));
        
 
        return find_partition(nums,0,0,0,dp);
    }
};