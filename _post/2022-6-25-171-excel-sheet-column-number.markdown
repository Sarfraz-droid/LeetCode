---
layout: post
title: 171-excel-sheet-column-number
date: 2022-06-25T14:23:55.698Z
---

```
171. Excel Sheet Column NumberEasyGiven a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -&gt; 1
B -&gt; 2
C -&gt; 3
...
Z -&gt; 26
AA -&gt; 27
AB -&gt; 28 
...


&nbsp;
Example 1:

Input: columnTitle = "A"
Output: 1


Example 2:

Input: columnTitle = "AB"
Output: 28


Example 3:

Input: columnTitle = "ZY"
Output: 701


&nbsp;
Constraints:


	1 &lt;= columnTitle.length &lt;= 7
	columnTitle consists only of uppercase English letters.
	columnTitle is in the range ["A", "FXSHRXW"].

 
```

##Code
 ```
  class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle)
        {
			//d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a number like it's going to be C)

            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};
 
```