class Solution {
public:
    
    int findMax(vector<vector<int>> &dp,int i,vector<int> &vec,int maxi)
    {
        if(i >= vec.size())
        {
            return 0;
        }
        
        if(dp[i][maxi] != -1)
            return dp[i][maxi];
        
        int l = INT_MIN;
        int r = INT_MIN;
        if(i+2 < vec.size())
            l = findMax(dp,i+2,vec,maxi+vec[i+2]);
        
        r = findMax(dp,i+3,vec,maxi);
        
        return dp[i][maxi] = vec[i] + max(l,r);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return max(findMax(dp,0,nums,0),findMax(dp,1,nums,0));
    }
};