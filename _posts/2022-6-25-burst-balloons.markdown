---
layout: post
title: burst-balloons
date: 2022-06-25T14:52:08.125Z
---

```
312. Burst BalloonsHardYou are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

&nbsp;
Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --&gt; [3,5,8] --&gt; [3,8] --&gt; [8] --&gt; []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10


&nbsp;
Constraints:


	n == nums.length
	1 &lt;= n &lt;= 500
	0 &lt;= nums[i] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:

    int findMaxCounts(vector<int>& nums,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=j)
        {
            return 0;
        }
        
        int ans = INT_MIN;
        
        if(dp[i][j] != 0)
            return dp[i][j];
        
        for(int k = i;k<j;k++)
        {
            int tempans = findMaxCounts(nums,i,k,dp) + findMaxCounts(nums,k+1,j,dp) + nums[i-1]*nums[k]*nums[j];
            
            ans = max(tempans,ans);

        }
        
        return dp[i][j] = ans;
        
    }
    
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
                vector<vector<int>> dp(nums.size(),vector<int>(nums.size()));

        return findMaxCounts(nums,1,nums.size()-1,dp);
    }
}; 
```