---
layout: post
title: 799-champagne-tower
date: 2022-06-25T14:52:08.096Z
---

```
799. Champagne TowerMediumWe stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.&nbsp; Each glass holds one cup&nbsp;of champagne.

Then, some champagne is poured into the first glass at the top.&nbsp; When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.&nbsp; When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.&nbsp; (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.&nbsp; After two cups of champagne are poured, the two glasses on the second row are half full.&nbsp; After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.&nbsp; After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.



Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is (both i and j are 0-indexed.)

&nbsp;
Example 1:

Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.


Example 2:

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.


Example 3:

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000


&nbsp;
Constraints:


	0 &lt;=&nbsp;poured &lt;= 109
	0 &lt;= query_glass &lt;= query_row&nbsp;&lt; 100
 
```

##Code
 ```
  class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
         vector<vector<double>> dp(101,vector<double>(101,0));
        query_row++;
        query_glass++;
        dp[1][1] = poured;
        for(int i = 2;i<=(query_row);i++){
            for(int j = 1;j<=i;j++){
                double sum = 0;
                if(dp[i-1][j] > 1){
                    sum+=double(dp[i-1][j]-1)/2;
                }
                
                if(dp[i-1][j-1] > 1){
                    sum+=double(dp[i-1][j-1]-1)/2;
                }
                dp[i][j] = sum;
            }
        }
        
        return dp[query_row][query_glass] > 1 ? double(1) : dp[query_row][query_glass];
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 799-champagne-tower
date: 2022-06-25T14:52:08.096Z
---

```
​ 
```
