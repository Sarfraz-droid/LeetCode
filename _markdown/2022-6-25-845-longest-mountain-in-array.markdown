---
layout: post
title: 845-longest-mountain-in-array
date: 2022-06-25T14:20:30.407Z
---

```
845. Longest Mountain in ArrayMediumYou may recall that an array arr is a mountain array if and only if:


	arr.length &gt;= 3
	There exists some index i (0-indexed) with 0 &lt; i &lt; arr.length - 1 such that:
	
		arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]
		arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]
	
	


Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

&nbsp;
Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.


Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.


&nbsp;
Constraints:


	1 &lt;= arr.length &lt;= 104
	0 &lt;= arr[i] &lt;= 104


&nbsp;
Follow up:


	Can you solve it using only one pass?
	Can you solve it in O(1) space?

 
```

##Code
 ```
  class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = n-1;
        for(int i = 1;i<n;i++){
            if(arr[i-1] >= arr[i]){
                left[i] = i;
            }else{
                left[i] = left[i-1];
            }
            
            int j = n-1-i;
            
            if(arr[j+1] >= arr[j]){
                right[j] = j;
            }else{
                right[j] = right[j+1];
            }
        }

        
        int maxmount = INT_MIN;
        for(int i = 0;i<n;i++){
            if(left[i] == i or right[i] == i)
                maxmount = max(maxmount,0);
            else{
                int len = right[i] - left[i]+1;            
                maxmount = max(maxmount,len);
            }
        }
        
        return maxmount;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 845-longest-mountain-in-array
date: 2022-06-25T14:20:30.407Z
---

```
​ 
```
