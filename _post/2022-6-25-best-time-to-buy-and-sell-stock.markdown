---
layout: post
title: best-time-to-buy-and-sell-stock
date: 2022-06-25T14:23:55.808Z
---

```
121. Best Time to Buy and Sell StockEasyYou are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

&nbsp;
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


&nbsp;
Constraints:


	1 &lt;= prices.length &lt;= 105
	0 &lt;= prices[i] &lt;= 104

 
```

##Code
 ```
  class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n),dp2(n);
        
        for(int i=0,j=n-1;i<n,j>=0;i++,j--)
        {
            if(i==0)
            {
                dp1[i] = prices[i];
                dp2[j] = prices[j];
            }else
            {
                dp1[i] = min(dp1[i-1],prices[i]);
                dp2[j] = max(dp2[j+1],prices[j]);
            }
            
        }
        int ans = INT_MIN;
        
        for(int i = 0;i<n;i++)
        {
            ans = max(ans,dp2[i]-dp1[i]);
        }

        
        return ans;
    }
}; 
```