---
layout: post
title: largest-divisible-subset
date: 2022-06-25T14:28:05.081Z
---

```
368. Largest Divisible SubsetMediumGiven a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:


	answer[i] % answer[j] == 0, or
	answer[j] % answer[i] == 0


If there are multiple solutions, return any of them.

&nbsp;
Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.


Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 1000
	1 &lt;= nums[i] &lt;= 2 * 109
	All the integers in nums are unique.

 
```

##Code
 ```
  class Solution {
public:
    vector<int> ans;
    vector<int> dp;
    void lds(vector<int> temp,int i,int prev,vector<int>& nums){
        if(i>=nums.size()){
            if(temp.size()>ans.size()) ans=temp;
            return;
        }
//We can't directly use temp.size() without typecasting because it will return an unsigned int and hence if() will not work.
        if((int)temp.size()>dp[i] && (nums[i]%prev==0)){ 
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            lds(temp,i+1,nums[i],nums);
            temp.pop_back();
        }
        lds(temp,i+1,prev,nums);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++) dp.push_back(-1);
        vector<int> temp;
        lds(temp,0,1,nums);
        return ans;
    }
}; 
```