---
layout: post
title: 221-maximal-square
date: 2022-06-25T14:28:04.976Z
---

```
221. Maximal SquareMediumGiven an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

&nbsp;
Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4


Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1


Example 3:

Input: matrix = [["0"]]
Output: 0


&nbsp;
Constraints:


	m == matrix.length
	n == matrix[i].length
	1 &lt;= m, n &lt;= 300
	matrix[i][j] is '0' or '1'.

 
```

##Code
 ```
  class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans = 0;
        
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    ans = max(dp[i][j],ans);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans*ans;
        
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 221-maximal-square
date: 2022-06-25T14:28:04.976Z
---

```
​ 
```
