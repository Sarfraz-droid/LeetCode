---
layout: post
title: climbing-stairs
date: 2022-06-25T14:23:55.810Z
---

```
70. Climbing StairsEasyYou are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

&nbsp;
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


&nbsp;
Constraints:


	1 &lt;= n &lt;= 45

 
```

##Code
 ```
  class Solution {
public:

    int calculate_stairs(int n,vector<int> &dp)
    {
        if(n <= 1)
            return 1;
        
        if(dp[n] != 0)
            return dp[n];
        
        return dp[n] = calculate_stairs(n-1,dp) + calculate_stairs(n-2,dp);
 
    }
        
    int climbStairs(int n) {
        vector<int> dp(n+1);
        
        return calculate_stairs(n,dp);
    }
}; 
```