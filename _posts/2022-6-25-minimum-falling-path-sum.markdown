---
layout: post
title: minimum-falling-path-sum
date: 2022-06-25T14:28:05.083Z
---

```
931. Minimum Falling Path SumMediumGiven an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

&nbsp;
Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]


Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]


Example 3:

Input: matrix = [[-48]]
Output: -48


&nbsp;
Constraints:


	n == matrix.length
	n == matrix[i].length
	1 &lt;= n &lt;= 100
	-100 &lt;= matrix[i][j] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    int minsum;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        minsum = INT_MAX;
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int l = (j-1) >= 0 ? matrix[i-1][j-1] : INT_MAX;
                int c = matrix[i-1][j];
                int r = (j+1 < n) ? matrix[i-1][j+1] : INT_MAX;
                
                matrix[i][j] += min(l, min(c,r));
            }
        }
        
        for(int j = 0;j<n;j++)
        {
            minsum = min(minsum,matrix[n-1][j]);
        }
        
        return minsum;
    }
    
    int findPaths(vector<vector<int>>& matrix,int i,int j,int n,int sum,vector<vector<int>>& dp)
    {
        if(j<0 || j>=n || i < 0)
            return INT_MAX;
        
        if(i == n)
        {
            minsum = min(sum,minsum);
            return sum;
        }
        
        sum+=matrix[i][j];
        
        return dp[i][j] = min(findPaths(matrix,i+1,j+1,n,sum,dp),min(findPaths(matrix,i+1,j-1,n,sum,dp),findPaths(matrix,i+1,j,n,sum,dp)));
    }
}; 
```