---
layout: post
title: 424-longest-repeating-character-replacement
date: 2022-06-25T14:23:55.762Z
---

```
424. Longest Repeating Character ReplacementMediumYou are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

&nbsp;
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.


Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 105
	s consists of only uppercase English letters.
	0 &lt;= k &lt;= s.length

 
```

##Code
 ```
  class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        int max_cnt = 0,ans = 0;
        
        while(j < s.size()){
            mp[s[j]]++;
            max_cnt = max(max_cnt,mp[s[j]]);
            while((j-i+1) - max_cnt > k){
                mp[s[i]]--;
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 424-longest-repeating-character-replacement
date: 2022-06-25T14:23:55.762Z
---

```
​ 
```
