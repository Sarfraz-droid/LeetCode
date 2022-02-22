class Solution {
public:
    int maxsum = 0;
    int num;
    int dp[101][101];
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        num = n;
        return helper(cuts,0,n,0,cuts.size()-1);
    }
    
    int helper(vector<int>& cuts,int l,int r,int ci,int cj){
        if(ci > cj)
        {
            return 0;
        }
        
        if(dp[ci][cj] != -1) return dp[ci][cj];
        
        int cost = 1e7;
        for(int k = ci;k<=cj;++k){
            cost = min(cost,helper(cuts,l,cuts[k],ci,k-1) + helper(cuts,cuts[k],r,k+1,cj));
        }
        
        return dp[ci][cj] = cost + (r-l);
    }
};