---
layout: post
title: unique-paths
date: 2022-06-25T14:28:05.125Z
---

```
62. Unique PathsMediumA robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

&nbsp;
Example 1:

Input: m = 3, n = 7
Output: 28


Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right
3. Down -&gt; Right -&gt; Down


Example 3:

Input: m = 7, n = 3
Output: 28


Example 4:

Input: m = 3, n = 3
Output: 6


&nbsp;
Constraints:


	1 &lt;= m, n &lt;= 100
	It's guaranteed that the answer will be less than or equal to 2 * 109.

 
```

##Code
 ```
  class Solution {
public:
    

    
    int uniquePaths(int m, int n) {
        int ans = 0;
        
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == 0|| j == 0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
}; 
```