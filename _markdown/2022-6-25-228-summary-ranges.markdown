---
layout: post
title: 228-summary-ranges
date: 2022-06-25T14:20:30.327Z
---

```
228. Summary RangesEasyYou are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:


	"a-&gt;b" if a != b
	"a" if a == b


&nbsp;
Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0-&gt;2","4-&gt;5","7"]
Explanation: The ranges are:
[0,2] --&gt; "0-&gt;2"
[4,5] --&gt; "4-&gt;5"
[7,7] --&gt; "7"


Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2-&gt;4","6","8-&gt;9"]
Explanation: The ranges are:
[0,0] --&gt; "0"
[2,4] --&gt; "2-&gt;4"
[6,6] --&gt; "6"
[8,9] --&gt; "8-&gt;9"


&nbsp;
Constraints:


	0 &lt;= nums.length &lt;= 20
	-231 &lt;= nums[i] &lt;= 231 - 1
	All the values of nums are unique.
	nums is sorted in ascending order.

 
```

##Code
 ```
  class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int l = -1,r = -1;
        
        for(int i =0;i<nums.size();i++){
            if(l == -1){
                l = i;
                continue;
            }
            
            if(r == -1){
                if(nums[l]+1 == nums[i]){
                    r = i;
                }else{
                    ans.push_back(to_string(nums[l]));
                    l = i;
                }
            }else{
                if(nums[r]+1 == nums[i]){
                    r = i;
                }else{
                    ans.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
                    l = i;
                    r = -1;
                }
            }
        }
        
        
        if(r == -1 and l != -1){
            ans.push_back(to_string(nums[l]));
        }else if(r != -1 and l != -1){
            ans.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
        }
        
        return ans;
    }
}; 
```