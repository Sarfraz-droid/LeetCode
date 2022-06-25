---
layout: post
title: 413-arithmetic-slices
date: 2022-06-25T14:20:30.388Z
---

```
413. Arithmetic SlicesMediumAn integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.


	For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.


Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

&nbsp;
Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.


Example 2:

Input: nums = [1]
Output: 0


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 5000
	-1000 &lt;= nums[i] &lt;= 1000

 
```

##Code
 ```
  class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        vector<int> sum(n-1);
        
        for(int  i =1;i<n;i++){
            sum[i-1] = nums[i]-nums[i-1];
        }
        
        vector<int> count(n-1);
        
        for(int i = 1;i<sum.size();i++){
            if(sum[i-1] == sum[i])
                count[i] = count[i-1]+1;
        }
        
        return accumulate(count.begin(),count.end(),0);
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 413-arithmetic-slices
date: 2022-06-25T14:20:30.388Z
---

```
​ 
```
