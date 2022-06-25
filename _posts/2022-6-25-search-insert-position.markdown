---
layout: post
title: search-insert-position
date: 2022-06-25T14:20:30.521Z
---

```
35. Search Insert PositionEasyGiven a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must&nbsp;write an algorithm with&nbsp;O(log n) runtime complexity.

&nbsp;
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:
Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:
Input: nums = [1], target = 0
Output: 0

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 104
	-104 &lt;= nums[i] &lt;= 104
	nums contains distinct values sorted in ascending order.
	-104 &lt;= target &lt;= 104

 
```

##Code
 ```
  class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int f = 0;
        int l = nums.size() - 1;
        
        int index = nums.size();
        while(f<=l)
        {
            int mid = (f+l)/2;
            
            if(nums[mid] < target)
            {
                f = mid+1;
            }else if(nums[mid] > target)
            {
                index = mid;
                l = mid-1;
            }else
            {
                index = mid;
                break;
            }
        }
        return index;
    }
}; 
```