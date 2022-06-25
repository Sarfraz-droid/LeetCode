---
layout: post
title: 136-single-number
date: 2022-06-25T14:52:08.031Z
---

```
136. Single NumberEasyGiven a non-empty&nbsp;array of integers nums, every element appears twice except for one. Find that single one.

You must&nbsp;implement a solution with a linear runtime complexity and use&nbsp;only constant&nbsp;extra space.

&nbsp;
Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
Output: 1

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 3 * 104
	-3 * 104 &lt;= nums[i] &lt;= 3 * 104
	Each element in the array appears twice except for one element which appears only once.

 
```

##Code
 ```
  class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int ans = 0;
        for(auto x : nums)
            ans ^= x;
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 136-single-number
date: 2022-06-25T14:52:08.030Z
---

```
​ 
```
