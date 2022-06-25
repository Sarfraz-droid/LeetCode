---
layout: post
title: 1480-running-sum-of-1d-array
date: 2022-06-25T14:20:30.308Z
---

```
1480. Running Sum of 1d ArrayEasyGiven an array nums. We define a running sum of an array as&nbsp;runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

&nbsp;
Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 1000
	-10^6&nbsp;&lt;= nums[i] &lt;=&nbsp;10^6
 
```

##Code
 ```
  class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++) nums[i] +=nums[i-1];
        return nums;
    }
}; 
```