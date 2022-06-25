---
layout: post
title: decode-string
date: 2022-06-25T14:23:55.813Z
---

```
394. Decode StringMediumGiven an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

&nbsp;
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 30
	s consists of lowercase English letters, digits, and square brackets '[]'.
	s is guaranteed to be a valid input.
	All the integers in s are in the range [1, 300].

 
```

##Code
 ```
  class Solution {
public:
    
    string decode(string str,int& idx)
    {
        if(idx >= str.size())
            return "";
        string ans = "";
        int num = 0;
            
        while(idx<str.size() and isalpha(str[idx])) 
            ans.push_back(str[idx++]);
        
        while(isdigit(str[idx]))
        {
            num = num*10 + (str[idx] - '0');
            idx++;
        }
    
        if(str[idx] == ']')
            return ans;
        idx+= 1;

        string temp = decode(str,idx);        
        string res = "";
                
        for(int i = 0;i < num;i++)res += temp;
        idx += 1;
        return ans + res + decode(str, idx);

        
    }
    
    string decodeString(string s) {
        int idx = 0;
        
       return decode(s, idx);
    }
}; 
```