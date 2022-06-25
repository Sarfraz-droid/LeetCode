---
layout: post
title: 905-sort-array-by-parity
date: 2022-06-25T14:52:08.099Z
---

```
905. Sort Array By ParityEasyGiven an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

&nbsp;
Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Example 2:

Input: nums = [0]
Output: [0]


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 5000
	0 &lt;= nums[i] &lt;= 5000

 
```

##Code
 ```
  class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 0){
                swap(nums[pos],nums[i]);
                pos++;
            }
        }
        
        return nums;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 905-sort-array-by-parity
date: 2022-06-25T14:52:08.099Z
---

```
​ 
```
