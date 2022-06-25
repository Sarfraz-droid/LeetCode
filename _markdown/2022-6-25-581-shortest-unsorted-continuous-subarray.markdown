---
layout: post
title: 581-shortest-unsorted-continuous-subarray
date: 2022-06-25T14:20:30.401Z
---

```
581. Shortest Unsorted Continuous SubarrayMediumGiven an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

&nbsp;
Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.


Example 2:

Input: nums = [1,2,3,4]
Output: 0


Example 3:

Input: nums = [1]
Output: 0


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 104
	-105 &lt;= nums[i] &lt;= 105


&nbsp;
Follow up: Can you solve it in O(n) time complexity? 
```

##Code
 ```
  class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1,end = -1,maxVal = INT_MIN;
        
        for(int i = 0;i<nums.size();i++){
            if(maxVal > nums[i]){
                if(start == -1) start = i-1;
                while(start >= 1 and nums[start-1] > nums[i]) start--;
                end = i+1;
            }else
                maxVal = nums[i];
        }
        
        return end - start;
    }
}; 
```