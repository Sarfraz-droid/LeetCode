class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n),dp2(n);
        
        for(int i=0,j=n-1;i<n,j>=0;i++,j--)
        {
            if(i==0)
            {
                dp1[i] = prices[i];
                dp2[j] = prices[j];
            }else
            {
                dp1[i] = min(dp1[i-1],prices[i]);
                dp2[j] = max(dp2[j+1],prices[j]);
            }
            
        }
        int ans = INT_MIN;
        
        for(int i = 0;i<n;i++)
        {
            ans = max(ans,dp2[i]-dp1[i]);
        }

        
        return ans;
    }
};