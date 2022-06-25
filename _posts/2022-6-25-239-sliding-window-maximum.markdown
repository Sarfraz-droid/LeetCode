---
layout: post
title: 239-sliding-window-maximum
date: 2022-06-25T14:28:04.978Z
---

```
239. Sliding Window MaximumHardYou are given an array of integers&nbsp;nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

&nbsp;
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


Example 2:

Input: nums = [1], k = 1
Output: [1]


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 105
	-104 &lt;= nums[i] &lt;= 104
	1 &lt;= k &lt;= nums.length

 
```

##Code
 ```
  class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(!dq.empty() and dq.front() == i-k) dq.pop_front();
            
            while(!dq.empty() and nums[dq.back()] < nums[i])
                dq.pop_back();
            
            
            dq.push_back(i);
            if(i >= k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 239-sliding-window-maximum
date: 2022-06-25T14:28:04.978Z
---

```
​ 
```
