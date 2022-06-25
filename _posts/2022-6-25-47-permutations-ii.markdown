---
layout: post
title: 47-permutations-ii
date: 2022-06-25T14:52:08.067Z
---

```
47. Permutations IIMediumGiven a collection of numbers, nums,&nbsp;that might contain duplicates, return all possible unique permutations in any order.

&nbsp;
Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]


Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 8
	-10 &lt;= nums[i] &lt;= 10

 
```

##Code
 ```
  class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        combinations(nums,0);
        return ans;
    }
    
    void combinations(vector<int>& nums,int i)
    {
        if(i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;

        for(int j = i;j<nums.size();j++)
        {
            if(s.find(nums[j])!=s.end())continue;
            s.insert(nums[j]);
            swap(nums[i],nums[j]);
            combinations(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    
}; 
```
##NOTES.md
 ---
layout: post
title: 47-permutations-ii
date: 2022-06-25T14:52:08.067Z
---

```
​ 
```
