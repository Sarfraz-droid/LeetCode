---
layout: post
title: longest-common-prefix
date: 2022-06-25T14:20:30.450Z
---

```
14. Longest Common PrefixEasyWrite a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

&nbsp;
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"


Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


&nbsp;
Constraints:


	1 &lt;= strs.length &lt;= 200
	0 &lt;= strs[i].length &lt;= 200
	strs[i] consists of only lower-case English letters.

 
```

##Code
 ```
  class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        
        for(int i = 0;i<strs[0].size();i++)
        {
            char ch = strs[0][i];
            for(int j = 1;j<strs.size();j++)
            {
                if(strs[j][i] != ch)
                {
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        
        return ans;
    }
}; 
```