---
layout: post
title: 1689-partitioning-into-minimum-number-of-deci-binary-numbers
date: 2022-06-25T14:28:04.967Z
---

```
1689. Partitioning Into Minimum Number Of Deci-Binary NumbersMediumA decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

&nbsp;
Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32


Example 2:

Input: n = "82734"
Output: 8


Example 3:

Input: n = "27346209830709182346"
Output: 9


&nbsp;
Constraints:


	1 &lt;= n.length &lt;= 105
	n consists of only digits.
	n does not contain any leading zeros and represents a positive integer.

 
```

##Code
 ```
  class Solution {
public:
    int minPartitions(string n) {
        int len = n.size();
        int ans = 0;
        for(int i = 0;i<len;i++){
            int k = n[i] - '0';
            ans = max(ans,k);
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1689-partitioning-into-minimum-number-of-deci-binary-numbers
date: 2022-06-25T14:28:04.967Z
---

```
​ 
```
