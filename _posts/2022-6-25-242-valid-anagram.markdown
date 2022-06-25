---
layout: post
title: 242-valid-anagram
date: 2022-06-25T14:52:08.052Z
---

```
242. Valid AnagramEasyGiven two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

&nbsp;
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false

&nbsp;
Constraints:


	1 &lt;= s.length, t.length &lt;= 5 * 104
	s and t consist of lowercase English letters.


&nbsp;
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 
```

##Code
 ```
  class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp_s(26);
        
        vector<int> mp_t(26);
        
        for(auto ch: s){
            mp_s[ch-'a']++;
        }
        
        for(auto ch:t){
            mp_t[ch-'a']++;
        }
        
        return mp_s == mp_t;
    }
}; 
```