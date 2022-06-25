---
layout: post
title: find-kth-bit-in-nth-binary-string
date: 2022-06-25T14:52:08.132Z
---

```
1545. Find Kth Bit in Nth Binary StringMediumGiven two positive integers&nbsp;n&nbsp;and k,&nbsp;the binary string&nbsp;&nbsp;Sn&nbsp;is formed as follows:


	S1&nbsp;= "0"
	Si&nbsp;=&nbsp;Si-1&nbsp;+ "1" + reverse(invert(Si-1))&nbsp;for&nbsp;i &gt; 1


Where&nbsp;+&nbsp;denotes the concatenation operation,&nbsp;reverse(x)&nbsp;returns the reversed string x,&nbsp;and&nbsp;invert(x)&nbsp;inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first 4 strings in the above sequence are:


	S1&nbsp;= "0"
	S2&nbsp;= "011"
	S3&nbsp;= "0111001"
	S4 = "011100110110001"


Return the kth bit in&nbsp;Sn. It is guaranteed that&nbsp;k&nbsp;is valid for the given&nbsp;n.

&nbsp;
Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3&nbsp;is "0111001". The first bit is "0".


Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4&nbsp;is "011100110110001". The 11th bit is "1".


Example 3:

Input: n = 1, k = 1
Output: "0"


Example 4:

Input: n = 2, k = 3
Output: "1"


&nbsp;
Constraints:


	1 &lt;= n &lt;= 20
	1 &lt;= k &lt;= 2n - 1
 
```
