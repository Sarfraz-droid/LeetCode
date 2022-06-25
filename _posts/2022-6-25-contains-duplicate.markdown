---
layout: post
title: contains-duplicate
date: 2022-06-25T14:20:30.439Z
---

```
217. Contains DuplicateEasyGiven an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

&nbsp;
Example 1:
Input: nums = [1,2,3,1]
Output: true
Example 2:
Input: nums = [1,2,3,4]
Output: false
Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 105
	-109 &lt;= nums[i] &lt;= 109

 
```

##Code
 ```
  class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                return true;
        }
        return false;
    }
}; 
```