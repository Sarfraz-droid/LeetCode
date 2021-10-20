class Solution {
public:
    int dp[50][50];
    
    int max_find(vector<int> arr,int s,int e)
    {
        int mx = 0;
        
        for(int i = s;i<=e;i++)
        {
            mx = max(mx,arr[i]);
        }
        
        return mx;
    }
    
    int solve(vector<int>& arr,int s,int e)
    {
        if(s==e)
        {
            return 0;
        }
        
        if(dp[s][e] != -1)
            return dp[s][e];
        
        int ans = INT_MAX;
        
        for(int i =s;i<e;i++)
        {
            int lsum = max_find(arr,s,i);
            int rsum = max_find(arr,i+1,e);
            
            ans = min(ans,solve(arr,s,i) + solve(arr,i+1,e) + lsum*rsum);
        }
        
        return dp[s][e] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {        
        memset(dp, -1 , sizeof(dp));
        
        return solve(arr,0,arr.size()-1);
    }
};