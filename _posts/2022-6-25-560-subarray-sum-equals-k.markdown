---
layout: post
title: 560-subarray-sum-equals-k
date: 2022-06-25T14:28:05.031Z
---

```
560. Subarray Sum Equals KMediumGiven an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

&nbsp;
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 2 * 104
	-1000 &lt;= nums[i] &lt;= 1000
	-107 &lt;= k &lt;= 107

 
```

##Code
 ```
  class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // take the size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum
        
        prefix[0] = arr[0]; // for element at index at zero, it is same
        
        // making our prefix array
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // declare an unordered map
        
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }
            
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};
 
```
##NOTES.md
 ---
layout: post
title: 560-subarray-sum-equals-k
date: 2022-06-25T14:28:05.031Z
---

```
​ 
```
