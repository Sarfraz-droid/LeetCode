---
layout: post
title: 389-find-the-difference
date: 2022-06-25T14:28:04.985Z
---

```
389. Find the DifferenceEasyYou are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

&nbsp;
Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.


Example 2:

Input: s = "", t = "y"
Output: "y"


&nbsp;
Constraints:


	0 &lt;= s.length &lt;= 1000
	t.length == s.length + 1
	s and t consist of lowercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        
        for(auto x : s) mp[x]++;
        
        for(auto x : t)
        {
            if(mp[x] <= 0)
                return x;
            mp[x]--;
        }
        return t[s.size()];
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 389-find-the-difference
date: 2022-06-25T14:28:04.985Z
---

```
​ 
```
