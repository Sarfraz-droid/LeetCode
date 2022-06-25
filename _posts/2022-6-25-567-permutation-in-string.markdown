---
layout: post
title: 567-permutation-in-string
date: 2022-06-25T14:52:08.072Z
---

```
567. Permutation in StringMediumGiven two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

&nbsp;
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").


Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


&nbsp;
Constraints:


	1 &lt;= s1.length, s2.length &lt;= 104
	s1 and s2 consist of lowercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    bool checkInclusion(string p, string s) {
                int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) return true;
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window)return true;
        }
        
        return false;

    }
}; 
```
##NOTES.md
 ---
layout: post
title: 567-permutation-in-string
date: 2022-06-25T14:52:08.072Z
---

```
​ 
```
