---
layout: post
title: 532-k-diff-pairs-in-an-array
date: 2022-06-25T14:52:08.071Z
---

```
532. K-diff Pairs in an ArrayMediumGiven an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:


	0 &lt;= i &lt; j &lt; nums.length
	|nums[i] - nums[j]| == k


Notice that |val| denotes the absolute value of val.

&nbsp;
Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.


Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).


Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 104
	-107 &lt;= nums[i] &lt;= 107
	0 &lt;= k &lt;= 107

 
```

##Code
 ```
  class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(auto x : nums){
            mp[x]++;
        }
        
        int count = 0;
        for(auto x: mp){
            if(k == 0)
            {
                if(x.second > 1)
                    count++;
            }else{
                if(mp.find(x.first + k) != mp.end())
                    count++;
            }
        }
        
        return count;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 532-k-diff-pairs-in-an-array
date: 2022-06-25T14:52:08.070Z
---

```
​ 
```
