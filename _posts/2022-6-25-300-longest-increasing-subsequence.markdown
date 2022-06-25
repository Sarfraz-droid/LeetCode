---
layout: post
title: 300-longest-increasing-subsequence
date: 2022-06-25T14:20:30.339Z
---

```
300. Longest Increasing SubsequenceMediumGiven an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

&nbsp;
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4


Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 2500
	-104 &lt;= nums[i] &lt;= 104


&nbsp;
Follow up:&nbsp;Can you come up with an algorithm that runs in&nbsp;O(n log(n)) time complexity?
 
```

##Code
 ```
  class Solution {
public:
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> dp(nums.size(),-1);
        int ans = 1;
        dp[0] = 1;
        
        for(int i = 1;i<nums.size();i++){
            int imax = 0;
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i])
                {
                    if(dp[j] > imax){
                        imax = dp[j];
                    }
                }
            }
            
            dp[i] = imax + 1;
            ans = max(ans,dp[i]);
        }
        
        
        return ans;
    }
    

    
}; 
```
##NOTES.md
 ---
layout: post
title: 300-longest-increasing-subsequence
date: 2022-06-25T14:20:30.339Z
---

```
​ 
```
