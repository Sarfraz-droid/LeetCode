---
layout: post
title: 198-house-robber
date: 2022-06-25T14:28:04.973Z
---

```
198. House RobberMediumYou are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

&nbsp;
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.


Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 100
	0 &lt;= nums[i] &lt;= 400

 
```

##Code
 ```
  class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,0);
        
        for(int i = 1;i<=n;i++){
            if(i == 1 or i == 2){
                dp[i] = nums[i-1];
            }else{
                dp[i] = nums[i-1] + max(dp[i-2],dp[i-3]);
            }
        }
        
        return max(dp[n],dp[n-1]);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 198-house-robber
date: 2022-06-25T14:28:04.973Z
---

```
​ 
```
