---
layout: post
title: 474-ones-and-zeroes
date: 2022-06-25T14:23:55.768Z
---

```
474. Ones and ZeroesMediumYou are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

&nbsp;
Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is  { "10", "0001", "1", "0" } , so the answer is 4.
Other valid but smaller subsets include  { "0001", "1" }  and  { "10", "1", "0" } .
 { "111001" }  is an invalid subset because it contains 4 1's, greater than the maximum of 3.


Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is  { "0", "1" } , so the answer is 2.


&nbsp;
Constraints:


	1 &lt;= strs.length &lt;= 600
	1 &lt;= strs[i].length &lt;= 100
	strs[i] consists only of digits '0' and '1'.
	1 &lt;= m, n &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i<=strs.size();i++){
            pair<int,int> temp = countZerosandOne(strs[i-1]);
            for(int j = 0;j<=m;j++){
                for(int k = 0;k<=n;k++){
                    if(temp.first <= j and temp.second <= k)
                        dp[i][j][k] = max(1 + dp[i-1][j-temp.first][k-temp.second], dp[i-1][j][k]);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        
        return dp[strs.size()][m][n];
        
    }
    
    int helper(vector<string>& strs,int m,int n,int pos){
                
        if(m < 0 or n < 0)
        {
            return INT_MIN;
        }else if((m == 0 and n == 0) or pos == -1)
        {
            return 0;
        }
        
        if(dp[m][n][pos] > 0 and dp[m][n][pos] < strs.size())
        {
            return dp[m][n][pos];
        }
        
        
        
        pair<int,int> pr = countZerosandOne(strs[pos]);
        int inlc = 1+ helper(strs,m-pr.first,n-pr.second,pos-1);
        int dinlc =  helper(strs,m,n,pos-1);
        return dp[m][n][pos] = max(inlc,dinlc);
    
    }
    
    pair<int,int> countZerosandOne(string s){
        int zero = 0,one = 0;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0')
                zero++;
            else
                one++;
        }
        
        return {zero,one};
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 474-ones-and-zeroes
date: 2022-06-25T14:23:55.768Z
---

```
​ 
```
