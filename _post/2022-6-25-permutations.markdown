---
layout: post
title: permutations
date: 2022-06-25T14:23:55.828Z
---

```
46. PermutationsMediumGiven an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

&nbsp;
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:
Input: nums = [1]
Output: [[1]]

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 6
	-10 &lt;= nums[i] &lt;= 10
	All the integers of nums are unique.

 
```

##Code
 ```
  class Solution {
public:
    
    void Permuts(vector<vector<int>> &ans,vector<int> comb,vector<int> &nums)
    {
        cout<<nums.size();
        if(nums.size() == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            int k = nums[i];
            nums.erase(nums.begin()+i);
            comb.push_back(k);
            
            Permuts(ans,comb,nums);
            
            comb.pop_back();
            nums.insert(nums.begin()+i,1,k);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        Permuts(ans,comb,nums);
        
        return ans;
    }
}; 
```