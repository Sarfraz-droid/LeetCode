---
layout: post
title: next-permutation
date: 2022-06-25T14:20:30.455Z
---

```
31. Next PermutationMediumImplement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant&nbsp;extra memory.

&nbsp;
Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:
Input: nums = [1]
Output: [1]

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 100
	0 &lt;= nums[i] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
}; 
```