---
layout: post
title: 941-valid-mountain-array
date: 2022-06-25T14:28:05.049Z
---

```
941. Valid Mountain ArrayEasyGiven an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:


	arr.length &gt;= 3
	There exists some i with 0 &lt; i &lt; arr.length - 1 such that:
	
		arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i] 
		arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]
	
	


&nbsp;
Example 1:
Input: arr = [2,1]
Output: false
Example 2:
Input: arr = [3,5,5]
Output: false
Example 3:
Input: arr = [0,3,2,1]
Output: true

&nbsp;
Constraints:


	1 &lt;= arr.length &lt;= 104
	0 &lt;= arr[i] &lt;= 104

 
```

##Code
 ```
  class Solution
{
public:
     bool validMountainArray(vector<int> &arr)
     {

          int length = arr.size();
          int i = 0;
          while (i < length - 1 && arr[i] < arr[i + 1])
          {
               i++;
          }
          if (i == length - 1 || i == 0)
          {
               return false;
          }
          while (i < length - 1 && arr[i] > arr[i + 1])
          {
               i++;
          }
          if (i == length - 1)
          {
               return true;
          }
          else
          {
               return false;
          }
     }
}; 
```
##NOTES.md
 ---
layout: post
title: 941-valid-mountain-array
date: 2022-06-25T14:28:05.049Z
---

```
​ 
```
