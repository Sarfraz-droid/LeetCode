---
layout: post
title: partition-equal-subset-sum
date: 2022-06-25T14:23:55.826Z
---

```
416. Partition Equal Subset SumMediumGiven a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

&nbsp;
Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 200
	1 &lt;= nums[i] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    
    bool find_partition(vector<int>& nums,int l,int r,int i,vector<vector<int>> &dp)
    {
                // cout<<l<<" "<<r<<" "<<i<<endl;

        if(i == nums.size())
            return l == r;
        
        if(dp[i][l] != -1)
            return dp[i][l];
    
        bool ans = find_partition(nums,l+nums[i],r,i+1,dp) or find_partition(nums,l,r+nums[i],i+1,dp);
        
        dp[i][l] = (int)ans;
        
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        
        // cout<<sum<<endl;
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1,-1));
        
 
        return find_partition(nums,0,0,0,dp);
    }
}; 
```