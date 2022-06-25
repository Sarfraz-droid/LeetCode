---
layout: post
title: 179-largest-number
date: 2022-06-25T14:52:08.043Z
---

```
179. Largest NumberMediumGiven a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

&nbsp;
Example 1:

Input: nums = [10,2]
Output: "210"


Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 100
	0 &lt;= nums[i] &lt;= 109

 
```

##Code
 ```
  class Solution {
public:
    
    static bool cmp(int &a,int &b){
        string cha = to_string(a);
        string chb = to_string(b);
        
        return cha+chb > chb+cha;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        
        string ans;
        for(auto x : nums){
            ans+= to_string(x);
        }
        
        cout<<ans;
        while(!ans.empty() and ans[0] == '0'){
            ans.erase(ans.begin());
            
        }
            
        return ans.size() == 0 ? "0": ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 179-largest-number
date: 2022-06-25T14:52:08.043Z
---

```
​ 
```
