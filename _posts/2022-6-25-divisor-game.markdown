---
layout: post
title: divisor-game
date: 2022-06-25T14:52:08.130Z
---

```
1025. Divisor GameEasyAlice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:


	Choosing any x with 0 &lt; x &lt; n and n % x == 0.
	Replacing the number n on the chalkboard with n - x.


Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

&nbsp;
Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.


Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


&nbsp;
Constraints:


	1 &lt;= n &lt;= 1000

 
```

##Code
 ```
  class Solution {
public:
    vector<int> dp;
    
    int helper(int n)
    {
        if(n == 1)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        for(int i = 1;i<n;i++)
        {
            if(n%i == 0)
            {
                if(helper(n-1) == 0)
                    return dp[n] = 1;
            }
        }
        
        return dp[n] = 0;
    }
    
    bool divisorGame(int n) {
        dp.resize(n+1);
        
        fill(dp.begin(),dp.end(),-1);
        
        return helper(n);
        
    }
}; 
```