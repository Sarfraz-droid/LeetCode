---
layout: post
title: count-primes
date: 2022-06-25T14:52:08.128Z
---

```
204. Count PrimesEasyCount the number of prime numbers less than a non-negative number, n.

&nbsp;
Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.


Example 2:

Input: n = 0
Output: 0


Example 3:

Input: n = 1
Output: 0


&nbsp;
Constraints:


	0 &lt;= n &lt;= 5 * 106

 
```

##Code
 ```
  class Solution {
public:
int countPrimes(int n) {
    vector prime(n, true);
    if(n==0 || n==1)
        return 0;
    prime[0] = false, prime[1] = false;
    for (int i = 2; i < sqrt(n); ++i) {
        if (prime[i]) {
            for (int j = 2*i; j < n; j += i) {
                prime[j] = false;
            }   
        }
    }
    return count(prime.begin(), prime.end(), true);
    }
};

 
```