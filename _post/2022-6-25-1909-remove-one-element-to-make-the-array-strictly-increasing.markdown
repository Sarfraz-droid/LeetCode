---
layout: post
title: 1909-remove-one-element-to-make-the-array-strictly-increasing
date: 2022-06-25T14:23:55.701Z
---

```
1909. Remove One Element to Make the Array Strictly IncreasingEasyGiven a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] &lt; nums[i] for each index (1 &lt;= i &lt; nums.length).

&nbsp;
Example 1:

Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.


Example 2:

Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.

Example 3:

Input: nums = [1,1,1]
Output: false
Explanation: The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.


&nbsp;
Constraints:


	2 &lt;= nums.length &lt;= 1000
	1 &lt;= nums[i] &lt;= 1000

 
```

##Code
 ```
  class Solution 
{
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        return checking(nums, 1, 1);
    }
private:
    bool checking(std::vector<int>& nums, int i, int delTime)
    {
        if (i >= nums.size())
            return true;
        
        if (nums[i] <= nums[i - 1])
        {
            if (delTime == 0)
                return false;
            
            delTime--;
            
            if (i == 1)
            {
                return checking(nums, i + 1, delTime);
            }
            else if (i < nums.size() - 1)
            {
                if (nums[i + 1] > nums[i - 1])
                    return checking(nums, i + 1, delTime);
                else
                {
                    nums[i - 1] = nums[i - 2];
                    return checking(nums, i, delTime);
                }
            }
            else
            {
                return checking(nums, i + 1, delTime);
            }
        }
        
        return checking(nums, i + 1, delTime);
    }
};
 
```