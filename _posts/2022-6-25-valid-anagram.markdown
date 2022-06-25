---
layout: post
title: valid-anagram
date: 2022-06-25T14:20:30.526Z
---

```
242. Valid AnagramEasyGiven two strings s and t, return true if t is an anagram of s, and false otherwise.

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
        if(s.size() != t.size())
            return false;
        
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i = 0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        for(int i = 0;i<n;i++)
        {
            if(mp[t[i]] == 0)
                return false;
            
            mp[t[i]]--;
        }
        return true;
    }
}; 
```