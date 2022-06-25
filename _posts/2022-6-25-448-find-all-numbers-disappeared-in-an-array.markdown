---
layout: post
title: 448-find-all-numbers-disappeared-in-an-array
date: 2022-06-25T14:20:30.392Z
---

```
448. Find All Numbers Disappeared in an ArrayEasyGiven an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

&nbsp;
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:
Input: nums = [1,1]
Output: [2]

&nbsp;
Constraints:


	n == nums.length
	1 &lt;= n &lt;= 105
	1 &lt;= nums[i] &lt;= n


&nbsp;
Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
```

##Code
 ```
  class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp(n+1);
        
        for(int i =0;i<n;i++){
            if(nums[i] <= n){
                temp[nums[i]]++;
            }
        }
        
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            if(temp[i] == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 448-find-all-numbers-disappeared-in-an-array
date: 2022-06-25T14:20:30.392Z
---

```
​ 
```
