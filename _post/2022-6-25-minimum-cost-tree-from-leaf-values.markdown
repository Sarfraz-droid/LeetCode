---
layout: post
title: minimum-cost-tree-from-leaf-values
date: 2022-06-25T14:23:55.825Z
---

```
1130. Minimum Cost Tree From Leaf ValuesMediumGiven an array arr of positive integers, consider all binary trees such that:


	Each node has either 0 or 2 children;
	The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
	The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.


Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

&nbsp;
Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.


Example 2:

Input: arr = [4,11]
Output: 44


&nbsp;
Constraints:


	2 &lt;= arr.length &lt;= 40
	1 &lt;= arr[i] &lt;= 15
	It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).

 
```

##Code
 ```
  class Solution {
public:
    int dp[50][50];
    
    int max_find(vector<int> arr,int s,int e)
    {
        int mx = 0;
        
        for(int i = s;i<=e;i++)
        {
            mx = max(mx,arr[i]);
        }
        
        return mx;
    }
    
    int solve(vector<int>& arr,int s,int e)
    {
        if(s==e)
        {
            return 0;
        }
        
        if(dp[s][e] != -1)
            return dp[s][e];
        
        int ans = INT_MAX;
        
        for(int i =s;i<e;i++)
        {
            int lsum = max_find(arr,s,i);
            int rsum = max_find(arr,i+1,e);
            
            ans = min(ans,solve(arr,s,i) + solve(arr,i+1,e) + lsum*rsum);
        }
        
        return dp[s][e] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {        
        memset(dp, -1 , sizeof(dp));
        
        return solve(arr,0,arr.size()-1);
    }
}; 
```