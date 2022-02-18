class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1);
        // dp[0] = 1;
        // // for(int i = 0;i<n;i++){
        // //     dp[i+1] = dp[i]*nums[i];
        // // }
        int ans = INT_MIN;
        vector<int> left(n+1);
        vector<int> right(n+1);
        left[0] = 1;
        
        for(int i = 0;i<n;i++){
            left[i+1] = left[i]*nums[i];
            // cout<<left[i+1]<<"\n";
            ans = max(left[i+1],ans);
            
            if(left[i+1] == 0) left[i+1] = 1;
        }
        
        right[n] = 1;
        
        for(int i = n-1;i>=0;i--){
            
            right[i] = right[i+1]*nums[i];
            ans = max(right[i],ans);
            if(right[i] == 0) right[i] = 1;
        }
        
        return ans;
    }
};