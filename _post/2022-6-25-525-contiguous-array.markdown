---
layout: post
title: 525-contiguous-array
date: 2022-06-25T14:23:55.772Z
---

```
525. Contiguous ArrayMediumGiven a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

&nbsp;
Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.


Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 105
	nums[i] is either 0 or 1.

 
```

##Code
 ```
  class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int temp = 0;
        int ans = 0;
        int n = nums.size();
        
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            temp += nums[i] == 0 ? -1 : 1;
            
            if(temp == 0)
            {
                ans = max(ans,i+1);
            }
            
            if(mp[temp] == 0){
                mp[temp] = i+1;
            }else{
                ans = max(ans,i+1-mp[temp]);
            }
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 525-contiguous-array
date: 2022-06-25T14:23:55.772Z
---

```
​ 
```
