---
layout: post
title: jump-game-ii
date: 2022-06-25T14:23:55.821Z
---

```
45. Jump Game IIMediumGiven an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

&nbsp;
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.


Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 104
	0 &lt;= nums[i] &lt;= 1000

 
```

##Code
 ```
  class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n-1;i++)
        {
            int lim = min(i+nums[i],n-1);
            for(int j=lim;j>i;j--)
            {
                if(dp[j]>dp[i]+1)dp[j]=dp[i]+1;
                else break;
            }
        }
        
        return dp[n-1];
    }

}; 
```