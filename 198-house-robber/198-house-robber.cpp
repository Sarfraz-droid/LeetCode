class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,0);
        
        for(int i = 1;i<=n;i++){
            if(i == 1 or i == 2){
                dp[i] = nums[i-1];
            }else{
                dp[i] = nums[i-1] + max(dp[i-2],dp[i-3]);
            }
        }
        
        return max(dp[n],dp[n-1]);
    }
};