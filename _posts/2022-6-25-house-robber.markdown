---
layout: post
title: house-robber
date: 2022-06-25T14:28:05.079Z
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
    
    int findMax(vector<vector<int>> &dp,int i,vector<int> &vec,int maxi)
    {
        if(i >= vec.size())
        {
            return 0;
        }
        
        if(dp[i][maxi] != -1)
            return dp[i][maxi];
        
        int l = INT_MIN;
        int r = INT_MIN;
        
        if(i+2 < vec.size())
            l = findMax(dp,i+2,vec,maxi+vec[i+2]);
        
        r = findMax(dp,i+3,vec,maxi);
        
        return dp[i][maxi] = vec[i] + max(l,r);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return max(findMax(dp,0,nums,0),findMax(dp,1,nums,0));
    }
}; 
```