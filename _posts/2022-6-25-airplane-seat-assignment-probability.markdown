---
layout: post
title: airplane-seat-assignment-probability
date: 2022-06-25T14:20:30.435Z
---

```
1227. Airplane Seat Assignment ProbabilityMediumn&nbsp;passengers board an airplane with exactly&nbsp;n&nbsp;seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:


	Take their own seat if it is still available,&nbsp;
	Pick other seats randomly when they find their seat occupied&nbsp;


What is the probability that the n-th person can get his own seat?

&nbsp;
Example 1:

Input: n = 1
Output: 1.00000
Explanation: The first person can only get the first seat.

Example 2:

Input: n = 2
Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).


&nbsp;
Constraints:


	1 &lt;= n &lt;= 10^5
 
```

##Code
 ```
  class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n== 1)
        {
            return 1;
        }else 
            return (double)1/2;
    }
}; 
```