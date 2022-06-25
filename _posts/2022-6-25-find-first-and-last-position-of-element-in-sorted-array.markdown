---
layout: post
title: find-first-and-last-position-of-element-in-sorted-array
date: 2022-06-25T14:20:30.445Z
---

```
34. Find First and Last Position of Element in Sorted ArrayMediumGiven an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must&nbsp;write an algorithm with&nbsp;O(log n) runtime complexity.

&nbsp;
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

&nbsp;
Constraints:


	0 &lt;= nums.length &lt;= 105
	-109&nbsp;&lt;= nums[i]&nbsp;&lt;= 109
	nums is a non-decreasing array.
	-109&nbsp;&lt;= target&nbsp;&lt;= 109

 
```

##Code
 ```
  class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol(2);
        sol[0] = -1;
        sol[1] = -1;
        
        int f = 0;
        int l = nums.size() -1;
        while(f <= l)
        {
            int mid = (f+l)/2;
            
            if(nums[mid] < target)
            {
                f = mid+1;
            }else if(nums[mid] > target)
            {
                l = mid - 1;
            }else
            {
                sol[0] = mid;
                l = mid-1;
            }
        }
        
        f = 0;
        l = nums.size()-1;
        
        while(f <= l)
        {
            int mid = (f+l)/2;
            
            if(nums[mid] < target)
            {
                f = mid+1;
            }else if(nums[mid] > target)
            {
                l = mid - 1;
            }else
            {
                sol[1] = mid;
                f = mid + 1;
            }
        }
        return sol;
    }
}; 
```