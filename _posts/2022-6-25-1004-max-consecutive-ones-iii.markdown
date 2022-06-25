---
layout: post
title: 1004-max-consecutive-ones-iii
date: 2022-06-25T14:52:08.008Z
---

```
1004. Max Consecutive Ones IIIMediumGiven a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

&nbsp;
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 105
	nums[i] is either 0 or 1.
	0 &lt;= k &lt;= nums.length

 
```

##Code
 ```
  class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int l = 0,r = 0;
        int zero_count = 0;
        
        while(r < nums.size()){
            
            if(nums[r] == 0)
                zero_count++;
            r++;
            while(zero_count > k){
                if(nums[l] == 0)
                    zero_count--;
                l++;
            }
            
            ans = max(ans,r-l);
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1004-max-consecutive-ones-iii
date: 2022-06-25T14:52:08.007Z
---

```
​ 
```
