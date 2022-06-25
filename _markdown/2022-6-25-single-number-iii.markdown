---
layout: post
title: single-number-iii
date: 2022-06-25T14:20:30.522Z
---

```
[Discussion Post (created on 6/10/2021 at 19:0)](https://leetcode.com/problems/single-number-iii/discuss/1562776/Simple-Solution-using-HashMap)  
260. Single Number IIIMediumGiven an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an&nbsp;algorithm that runs in linear runtime complexity and uses&nbsp;only constant extra space.

&nbsp;
Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.


Example 2:

Input: nums = [-1,0]
Output: [-1,0]


Example 3:

Input: nums = [0,1]
Output: [1,0]


&nbsp;
Constraints:


	2 &lt;= nums.length &lt;= 3 * 104
	-231 &lt;= nums[i] &lt;= 231 - 1
	Each integer in nums will appear twice, only two integers will appear once.

 
```

##Code
 ```
  class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto x: mp)
        {
            if(x.second == 1)
                ans.push_back(x.first);
        }
        
        return ans;
    }
}; 
```