---
layout: post
title: longest-palindromic-substring
date: 2022-06-25T14:52:08.138Z
---

```
5. Longest Palindromic SubstringMediumGiven a string s, return&nbsp;the longest palindromic substring in s.

&nbsp;
Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.


Example 2:

Input: s = "cbbd"
Output: "bb"


Example 3:

Input: s = "a"
Output: "a"


Example 4:

Input: s = "ac"
Output: "a"


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 1000
	s consist of only digits and English letters.

 
```

##Code
 ```
  class Solution {
private:
    int low;
    int MaxLen;
public:
    
    void search(string s,int j,int k)
    {
        while(j>=0 && k<s.size() && s[j] == s[k])
        {
            j--;
            k++;
        }
        
        if(MaxLen < (k-j-1))
        {
            MaxLen = k-j-1;
            low = j + 1;
        }
    }
    
    string longestPalindrome(string s) {
        string ans;
        low = 0;
        MaxLen = 0;
        
        if(s.size() < 2)
            return s;
        
        for(int i = 0;i<s.size()-1;i++)
        {
            search(s,i,i);
            search(s,i,i+1);
        }
        
        return s.substr(low,MaxLen);
    }
}; 
```