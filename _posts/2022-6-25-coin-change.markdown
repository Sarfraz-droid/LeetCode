---
layout: post
title: coin-change
date: 2022-06-25T14:28:05.072Z
---

```
322. Coin ChangeMediumYou are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

&nbsp;
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


Example 2:

Input: coins = [2], amount = 3
Output: -1


Example 3:

Input: coins = [1], amount = 0
Output: 0


&nbsp;
Constraints:


	1 &lt;= coins.length &lt;= 12
	1 &lt;= coins[i] &lt;= 231 - 1
	0 &lt;= amount &lt;= 104

 
```

##Code
 ```
  class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        
        
        
    
        for(int i = 1;i<=amount;i++)
        {
            
            dp[i] = INT_MAX;
            for(int j = 0;j<coins.size();j++)
            {
                if(i-coins[j] >= 0 and dp[i-coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
}; 
```