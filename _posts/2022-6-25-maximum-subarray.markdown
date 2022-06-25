---
layout: post
title: maximum-subarray
date: 2022-06-25T14:28:05.082Z
---

```
53. Maximum SubarrayEasyGiven an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

&nbsp;
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


Example 2:

Input: nums = [1]
Output: 1


Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 3 * 104
	-105 &lt;= nums[i] &lt;= 105


&nbsp;
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 
```

##Code
 ```
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
            max_sum = max(sum,max_sum);
            if(sum < 0)
                sum = 0;    
            
        }
        return max_sum;
    }
}; 
```