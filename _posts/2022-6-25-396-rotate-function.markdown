---
layout: post
title: 396-rotate-function
date: 2022-06-25T14:20:30.341Z
---

```
396. Rotate FunctionMediumYou are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:


	F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].


Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

&nbsp;
Example 1:

Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.


Example 2:

Input: nums = [100]
Output: 0


&nbsp;
Constraints:


	n == nums.length
	1 &lt;= n &lt;= 105
	-100 &lt;= nums[i] &lt;= 100

 
```

##Code
 ```
  class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxprod = 0,lastprod = 0,n = nums.size();
        
        for(int i =0;i<n;i++){
            maxprod += i*nums[i];
        }
        
        lastprod = maxprod;
        
        for(int k = 1;k<n;k++){
            int change = sum - n*nums[n-k];
            int newprod = change + lastprod;
            lastprod = newprod;
            maxprod = max(newprod,maxprod);
        }
        
        return maxprod;
    }
    
};

// class Solution { // basically the change of product between rotations can be calculated by the observation that `change = sum-last_element*array.size` where the last_element is the last element of array before rotation.
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         int maxprod = 0, lastprod = 0, n = nums.size();
//         for(int i = 0; i < n; i++) // k = 0
//             maxprod += i*nums[i];
        
//         lastprod = maxprod;
        
//         for(int k = 1; k < n; k++) {
//             int change = sum-n*nums[n-k];
//             int newprod = change+lastprod;
//             lastprod = newprod;
//             maxprod = max(newprod,maxprod);
//         }
        
//         return maxprod;
//     }
// }; 
```
##NOTES.md
 ---
layout: post
title: 396-rotate-function
date: 2022-06-25T14:20:30.341Z
---

```
​ 
```
