---
layout: post
title: 5-longest-palindromic-substring
date: 2022-06-25T14:23:55.769Z
---

```
5. Longest Palindromic SubstringMediumGiven a string s, return the longest palindromic substring in s.

&nbsp;
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


Example 2:

Input: s = "cbbd"
Output: "bb"


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 1000
	s consist of only digits and English letters.

 
```

##Code
 ```
  class Solution {
public:
    int maxlen;
    int low;
    string longestPalindrome(string s) {
        
        string ans;
        maxlen = 0;
        low = 0;
        for(int i =0;i<s.size();i++){
            lString(i-1,i,s);
            lString(i,i,s);
        }
        
        return s.substr(low,maxlen);
    }
    
    void lString(int a,int b,string s){
        while(a>=0 and b<s.size() and s[a] == s[b])
        {
            a--;
            b++;
        }
        
        
        if(maxlen < (b-a-1)){
            maxlen = b-a-1;
            low = a+1;
        }
    } 
}; 
```
##NOTES.md
 ---
layout: post
title: 5-longest-palindromic-substring
date: 2022-06-25T14:23:55.768Z
---

```
​ 
```
