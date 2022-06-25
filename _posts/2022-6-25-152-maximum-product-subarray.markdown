---
layout: post
title: 152-maximum-product-subarray
date: 2022-06-25T14:20:30.308Z
---

```
152. Maximum Product SubarrayMediumGiven an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

&nbsp;
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 2 * 104
	-10 &lt;= nums[i] &lt;= 10
	The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 
```

##Code
 ```
  class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1);
        // dp[0] = 1;
        // // for(int i = 0;i<n;i++){
        // //     dp[i+1] = dp[i]*nums[i];
        // // }
        int ans = INT_MIN;
        vector<int> left(n+1);
        vector<int> right(n+1);
        left[0] = 1;
        
        for(int i = 0;i<n;i++){
            left[i+1] = left[i]*nums[i];
            // cout<<left[i+1]<<"\n";
            ans = max(left[i+1],ans);
            
            if(left[i+1] == 0) left[i+1] = 1;
        }
        
        right[n] = 1;
        
        for(int i = n-1;i>=0;i--){
            
            right[i] = right[i+1]*nums[i];
            ans = max(right[i],ans);
            if(right[i] == 0) right[i] = 1;
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 152-maximum-product-subarray
date: 2022-06-25T14:20:30.308Z
---

```
​ 
```
