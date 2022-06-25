---
layout: post
title: guess-number-higher-or-lower
date: 2022-06-25T14:20:30.448Z
---

```
374. Guess Number Higher or LowerEasyWe are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:


	-1: The number I picked is lower than your guess (i.e. pick &lt; num).
	1: The number I picked is higher than your guess (i.e. pick &gt; num).
	0: The number I picked is equal to your guess (i.e. pick == num).


Return the number that I picked.

&nbsp;
Example 1:
Input: n = 10, pick = 6
Output: 6
Example 2:
Input: n = 1, pick = 1
Output: 1
Example 3:
Input: n = 2, pick = 1
Output: 1
Example 4:
Input: n = 2, pick = 2
Output: 2

&nbsp;
Constraints:


	1 &lt;= n &lt;= 231 - 1
	1 &lt;= pick &lt;= n

 
```
