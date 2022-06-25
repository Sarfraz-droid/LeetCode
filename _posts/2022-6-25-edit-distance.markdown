---
layout: post
title: edit-distance
date: 2022-06-25T14:28:05.076Z
---

```
72. Edit DistanceHardGiven two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:


	Insert a character
	Delete a character
	Replace a character


&nbsp;
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -&gt; rorse (replace 'h' with 'r')
rorse -&gt; rose (remove 'r')
rose -&gt; ros (remove 'e')


Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -&gt; inention (remove 't')
inention -&gt; enention (replace 'i' with 'e')
enention -&gt; exention (replace 'n' with 'x')
exention -&gt; exection (replace 'n' with 'c')
exection -&gt; execution (insert 'u')


&nbsp;
Constraints:


	0 &lt;= word1.length, word2.length &lt;= 500
	word1 and word2 consist of lowercase English letters.

 
```
