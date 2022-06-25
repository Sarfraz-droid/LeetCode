---
layout: post
title: bitwise-and-of-numbers-range
date: 2022-06-25T14:28:05.070Z
---

```
201. Bitwise AND of Numbers RangeMediumGiven two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

&nbsp;
Example 1:

Input: left = 5, right = 7
Output: 4


Example 2:

Input: left = 0, right = 0
Output: 0


Example 3:

Input: left = 1, right = 2147483647
Output: 0


&nbsp;
Constraints:


	0 &lt;= left &lt;= right &lt;= 231 - 1

 
```

##Code
 ```
  class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if ((left == 0) || (right == 0)) return 0;
        
        // if there is a different amount of digits in binary - always will be zero
        if ((int)log2(left) != (int)log2(right)) return 0;

        long ans = left;
        
        for(long i = left;i<=right;i++)
        {
            ans = ans & i;
        }
        
        return ans;
    }
}; 
```