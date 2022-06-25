---
layout: post
title: 844-backspace-string-compare
date: 2022-06-25T14:23:55.782Z
---

```
844. Backspace String CompareEasyGiven two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

&nbsp;
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".


Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".


Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".


&nbsp;
Constraints:


	1 &lt;= s.length, t.length &lt;= 200
	s and t only contain lowercase letters and '#' characters.


&nbsp;
Follow up: Can you solve it in O(n) time and O(1) space?
 
```

##Code
 ```
  class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a1;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '#'){
                if(a1.size() > 0)
                    a1.pop_back();
            }else{
                a1.push_back(s[i]);
            }
        }
        
        string a2;
        for(int i = 0;i<t.size();i++){
            if(t[i] == '#'){
                if(a2.size() > 0) 
                    a2.pop_back();
            }else{
                a2.push_back(t[i]);
            }
        }
        
        return a1 == a2;
    }
}; 
```