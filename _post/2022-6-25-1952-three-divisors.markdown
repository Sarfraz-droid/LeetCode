---
layout: post
title: 1952-three-divisors
date: 2022-06-25T14:23:55.702Z
---

```
1952. Three DivisorsEasyGiven an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

&nbsp;
Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.


Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.


&nbsp;
Constraints:


	1 &lt;= n &lt;= 104

 
```

##Code
 ```
  class Solution {
public:
    bool isThree(int n) {
        if(n == 1|| n == 2 )
            return false;
        
        int count = 0;
        for(int i = 2;i<n;i++){
            
            if(n%i == 0){
                count++;
                
                if(count > 1)
                    return false;
            }
            
        }
        
        return count == 1 ? true : false;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1952-three-divisors
date: 2022-06-25T14:23:55.702Z
---

```
​ 
```
