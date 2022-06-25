---
layout: post
title: combination-sum-ii
date: 2022-06-25T14:52:08.126Z
---

```
40. Combination Sum IIMediumGiven a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates&nbsp;where the candidate numbers sum to target.

Each number in candidates&nbsp;may only be used once in the combination.

Note:&nbsp;The solution set must not contain duplicate combinations.

&nbsp;
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]


Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]


&nbsp;
Constraints:


	1 &lt;=&nbsp;candidates.length &lt;= 100
	1 &lt;=&nbsp;candidates[i] &lt;= 50
	1 &lt;= target &lt;= 30

 
```

##Code
 ```
  class Solution {
public:
    vector<vector<int>> ans;
    int value;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        value = target;
        
        combinations(temp,candidates,0,0);
        
        return ans;
        
    }
    
    void combinations(vector<int> temp, vector<int>& candidates,int pos,int sum)
    {
        // cout<<sum<<" ";
        if(sum == value)
        {  
            ans.push_back(temp);  
            return;
        }
        
        for(int i = pos;i<candidates.size();i++)
        {
            if(i > pos && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > (value-sum))
                break;
            temp.push_back(candidates[i]);
            combinations(temp,candidates,i+1,sum+candidates[i]);
            temp.pop_back();
        }
    }
    
}; 
```