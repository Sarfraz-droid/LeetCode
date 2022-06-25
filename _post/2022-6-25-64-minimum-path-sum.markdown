---
layout: post
title: 64-minimum-path-sum
date: 2022-06-25T14:23:55.776Z
---

```
64. Minimum Path SumMediumGiven a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

&nbsp;
Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


&nbsp;
Constraints:


	m == grid.length
	n == grid[i].length
	1 &lt;= m, n &lt;= 200
	0 &lt;= grid[i][j] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(i == 1)
                {
                    dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
                }else if(j == 1){
                    dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 64-minimum-path-sum
date: 2022-06-25T14:23:55.776Z
---

```
​ 
```
