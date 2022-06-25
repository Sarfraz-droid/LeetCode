---
layout: post
title: 540-single-element-in-a-sorted-array
date: 2022-06-25T14:23:55.773Z
---

```
540. Single Element in a Sorted ArrayMediumYou are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

&nbsp;
Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 105
	0 &lt;= nums[i] &lt;= 105

 
```

##Code
 ```
  class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0,high = n-2;
        
        while(low<=high){
            int mid = (low+high) >> 1;
            
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }else
                high= mid-1;
        }
        
        return nums[low];
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 540-single-element-in-a-sorted-array
date: 2022-06-25T14:23:55.773Z
---

```
​ 
```
