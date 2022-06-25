---
layout: post
title: 46-permutations
date: 2022-06-25T14:28:05.027Z
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
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        ans.clear();
        vector<bool> flag(n);
        vector<int> curr;   
        findPermutations(nums,curr,flag,n);
               
        return ans;
    }
    
    void findPermutations(vector<int>& nums,vector<int> curr,vector<bool>& flag,int n){
        if(n == curr.size()){
            ans.push_back(curr);
        }
        
        for(int i = 0;i<n;i++){
            if(flag[i]) continue;
            
            flag[i] = true;
            curr.push_back(nums[i]);
            findPermutations(nums,curr,flag,n);
            curr.pop_back();
            flag[i] = false;
        }
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 46-permutations
date: 2022-06-25T14:28:05.027Z
---

```
​ 
```
