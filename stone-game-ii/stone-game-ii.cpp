class Solution {
public:
    
    int dp[1001][1001];
    int solve(vector <int> &piles,int start,int m)
    {   
        //base condition
        if(start==piles.size()-1)return piles[piles.size()-1];
        
        //dp[start][m] is the maximum score that a person can get with starting index as start and a given m value
        if(dp[start][m]!=-1)return dp[start][m];
        
        int ans=0;
        //total sum
        int total=0;
     
        int n=piles.size();
        
        //total sum
        for(int i=start;i<piles.size();i++)
        {
            total+=piles[i];
        }
        
        for(int i = start;i<(start + 2*m);i++)
        {
            if(i<n)
            {
                int temp  = 0;
                temp = solve(piles,i+1,max(m,i+1-start));    
                ans = max(ans,total - temp);
            }else
            {
                break;
            }
        }
        
        //memoization
        return dp[start][m]=ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
      return solve(piles,0,1);   
    }};