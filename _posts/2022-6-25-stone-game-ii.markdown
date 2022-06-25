---
layout: post
title: stone-game-ii
date: 2022-06-25T14:28:05.121Z
---

```
1140. Stone Game IIMediumAlice and Bob continue their&nbsp;games with piles of stones.&nbsp; There are a number of&nbsp;piles&nbsp;arranged in a row, and each pile has a positive integer number of stones&nbsp;piles[i].&nbsp; The objective of the game is to end with the most&nbsp;stones.&nbsp;

Alice&nbsp;and Bob take turns, with Alice starting first.&nbsp; Initially, M = 1.

On each player's turn, that player&nbsp;can take all the stones in the first X remaining piles, where 1 &lt;= X &lt;= 2M.&nbsp; Then, we set&nbsp;M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice&nbsp;can get.

&nbsp;
Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 


Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104


&nbsp;
Constraints:


	1 &lt;= piles.length &lt;= 100
	1 &lt;= piles[i]&nbsp;&lt;= 104

 
```

##Code
 ```
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
```