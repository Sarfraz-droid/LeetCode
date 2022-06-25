---
layout: post
title: 96-unique-binary-search-trees
date: 2022-06-25T14:23:55.787Z
---

```
96. Unique Binary Search TreesMediumGiven an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

&nbsp;
Example 1:

Input: n = 3
Output: 5


Example 2:

Input: n = 1
Output: 1


&nbsp;
Constraints:


	1 &lt;= n &lt;= 19

 
```

##Code
 ```
  class Solution {
public:
    vector<int> dp;
    int catalan(int n){
        if(n <= 1)
            return 1;
        int res = 0;
        
        if(dp[n] != 0)
            return dp[n];
        
        for(int i = 0;i<=n-1;i++){
            res += catalan(i)*catalan(n-i-1);
        }
        
        return dp[n] = res;
    }
    
    int numTrees(int n) {
        dp.resize(100);
        return catalan(n);
    }
}; 
```