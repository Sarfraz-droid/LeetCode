---
layout: post
title: 4-median-of-two-sorted-arrays
date: 2022-06-25T14:23:55.714Z
---

```
4. Median of Two Sorted ArraysHardGiven two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

&nbsp;
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


&nbsp;
Constraints:


	nums1.length == m
	nums2.length == n
	0 &lt;= m &lt;= 1000
	0 &lt;= n &lt;= 1000
	1 &lt;= m + n &lt;= 2000
	-106 &lt;= nums1[i], nums2[i] &lt;= 106

 
```

##Code
 ```
  	class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

			vector<int> *arr1,*arr2;

			int m = nums1.size(),n=nums2.size(); //size of arrays

			bool odd = (m+n)%2;

			int t = (m+n)/2; //insert up to this value


			if (n==0){ //edge-case : nums2 is empty
				if (m%2){ //odd
					return nums1[m/2];
				}
				else{
					return ((double) nums1[m/2]+nums1[m/2-1])/2.0;
				}
			}
			if (m==0){ //edge-case : nums1 is empty
				if (n%2){ //odd
					return nums2[n/2];
				}
				else{
					return ((double) nums2[n/2]+nums2[n/2-1])/2.0;
				}
			}

			/*
			Both nums1 and nums2 are not empty
			*/

			if (m>=n){
					arr1=&nums1;
					arr2=&nums2;
			}
			else{
				arr1=&nums2;
				arr2=&nums1;
				int tmp = m;
				m=n;
				n=tmp; //switch m,n
			}

			if (!odd){ //trivial cases
				if ((*arr1)[m-1]<=(*arr2)[0]){//answer lies in arr1
					return (m==n) ? ((*arr1)[m-1]+(*arr2)[0])/2.0 : ((*arr1)[t]+(*arr1)[t-1])/2.0;
				}
				if ((*arr2)[n-1]<=(*arr1)[0]){
					return (m==n) ? ((*arr1)[0]+(*arr2)[n-1])/2.0 : ((*arr1)[t-n]+(*arr1)[t-n-1])/2.0;
				}
			}

			int hi = t;
			int lo = hi-n;
			int mid = (hi+lo)/2;

			//bisection
			while (hi-lo>1){
				mid = (hi+lo)/2;
				if ((*arr1)[mid]<=(*arr2)[t-mid]){  //need to increase mid //(*arr1)[lo]<=(*arr2)[chi-lo])
					lo=mid;
				}
				else{ //(*arr1)[hi]>(*arr2)[chi-hi])
					hi=mid;
				}
			}

			if (odd){ //odd, it is either the hi element in arr1, or the t-hi element in arr2
				if ((*arr1)[hi]<=(*arr2)[t-hi]){
					return (*arr1)[hi];
				}
				else{
					//return (t-hi)>=0 ? max((*arr2)[t-hi],(*arr1)[lo]) : (*arr1)[lo];
					return max((*arr2)[t-hi],(*arr1)[lo]);
				}
			}
			else{
				//note that the if (*arr2)[t-hi]<(*arr1)[lo], then the index of lo is (t-hi+1)+lo
				//arr1[lo] is the t-th element
				if ((*arr2)[t-hi]<(*arr1)[lo] && (t-hi+1)+lo==t){
					return (lo-1>=0) ? ((*arr1)[lo]+max((*arr1)[lo-1],(*arr2)[t-hi]))/2.0 : ((*arr1)[lo]+(*arr2)[t-hi])/2.0;
				}
				//arr1[hi] is the t-th element
				else if ((*arr1)[hi]<=(*arr2)[t-hi]){
					return (t-hi-1>=0) ? ((*arr1)[hi]+max((*arr1)[lo],(*arr2)[t-hi-1]))/2.0 : ((*arr1)[hi]+(*arr1)[lo])/2.0;
				}
				//arr2[t-hi] is the t-th element
				else{
					return (t-hi-1>=0) ? ((*arr2)[t-hi]+max((*arr1)[lo],(*arr2)[t-hi-1]))/2.0 : ((*arr2)[t-hi]+(*arr1)[lo])/2.0;
				}
			}

			return 0;
		}
	};
 
```
##NOTES.md
 ---
layout: post
title: 4-median-of-two-sorted-arrays
date: 2022-06-25T14:23:55.714Z
---

```
​ 
```
