---
layout: post
title: generate-parentheses
date: 2022-06-25T14:52:08.134Z
---

```
22. Generate ParenthesesMediumGiven n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

&nbsp;
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]

&nbsp;
Constraints:


	1 &lt;= n &lt;= 8

 
```

##Code
 ```
  class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        brackets(n,0,0,"",ans);
        return ans;
    }
    
    void brackets(int n,int open,int close,string s,vector<string> &ans)
    {
        if(s.size() == 2*n)
        {
            ans.push_back(s);
            return;
        }
        
        if(open < n)
        {
            brackets(n,open+1,close,s+'(',ans);
        }
        if(close < open)
        {
            brackets(n,open,close+1,s+')',ans);
        }
    }
    
    
}; 
```