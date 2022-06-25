---
layout: post
title: 58-length-of-last-word
date: 2022-06-25T14:23:55.774Z
---

```
58. Length of Last WordEasyGiven a string s consisting&nbsp;of some words separated by some number of spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

&nbsp;
Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.


Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.


Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 104
	s consists of only English letters and spaces ' '.
	There will be at least one word in s.

 
```

##Code
 ```
  class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        // int s_n = s.size();
        while(n >= 0 and s[n] == ' '){
            n--;
        }
        int len = 0;
        while(n >=0 and s[n] != ' '){
            len++;
            n--;
        }
        
        return len;
    }
}; 
```