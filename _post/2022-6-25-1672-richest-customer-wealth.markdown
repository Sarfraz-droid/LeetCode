---
layout: post
title: 1672-richest-customer-wealth
date: 2022-06-25T14:23:55.695Z
---

```
1672. Richest Customer WealthEasyYou are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

&nbsp;
Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.


Example 2:

Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.

Example 3:

Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17


&nbsp;
Constraints:


	m ==&nbsp;accounts.length
	n ==&nbsp;accounts[i].length
	1 &lt;= m, n &lt;= 50
	1 &lt;= accounts[i][j] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for(int i = 0;i<accounts.size();i++){
            int sum = accumulate(accounts[i].begin(),accounts[i].end(),0);
            maxWealth = max(maxWealth,sum);
        }
        
        return maxWealth;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1672-richest-customer-wealth
date: 2022-06-25T14:23:55.695Z
---

```
​ 
```
