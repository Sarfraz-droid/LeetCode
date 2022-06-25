---
layout: post
title: 63-unique-paths-ii
date: 2022-06-25T14:20:30.402Z
---

```
63. Unique Paths IIMediumA robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

&nbsp;
Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right -&gt; Right


Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1


&nbsp;
Constraints:


	m ==&nbsp;obstacleGrid.length
	n ==&nbsp;obstacleGrid[i].length
	1 &lt;= m, n &lt;= 100
	obstacleGrid[i][j] is 0 or 1.

 
```

##Code
 ```
  class Solution {
public:
    int ans;
    int m,n;
    int dp[100][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ans = 0;
        memset(dp,0,sizeof(dp));
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return helper(obstacleGrid,0,0);
    }
    
    int helper(vector<vector<int>>& obstacleGrid,int i,int j){

        if(i>=m or j >= n)
        {
            return 0;
        }
        
               
        if(obstacleGrid[i][j] == 1)
            return 0;
        
        if(i == m-1 and j == n-1)
        {    
            ans++;
            return 1;
        }
        
        
        if(dp[i][j] != 0){
            return dp[i][j];    
        }
 
        
        return dp[i][j] = helper(obstacleGrid,i+1,j) + helper(obstacleGrid,i,j+1);
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 63-unique-paths-ii
date: 2022-06-25T14:20:30.402Z
---

```
​ 
```
