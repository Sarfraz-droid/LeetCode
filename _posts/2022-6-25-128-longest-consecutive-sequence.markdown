---
layout: post
title: 128-longest-consecutive-sequence
date: 2022-06-25T14:52:08.025Z
---

```
128. Longest Consecutive SequenceMediumGiven an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in&nbsp;O(n)&nbsp;time.

&nbsp;
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


&nbsp;
Constraints:


	0 &lt;= nums.length &lt;= 105
	-109 &lt;= nums[i] &lt;= 109

 
```

##Code
 ```
  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        
        int prev = INT_MIN;
        
        int temp = 0,ans = 0;
        for(auto it: st){
            
            if(prev == INT_MIN){
                temp++;
                prev = it;
            }else{
                if(it == (prev+1)){
                    temp++;
                    prev++;
                }else{
                    temp = 1;
                    prev = it;
                }
            }
            ans = max(temp,ans);
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 128-longest-consecutive-sequence
date: 2022-06-25T14:52:08.025Z
---

```
​ 
```
