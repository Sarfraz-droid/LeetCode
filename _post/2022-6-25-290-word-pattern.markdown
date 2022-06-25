---
layout: post
title: 290-word-pattern
date: 2022-06-25T14:23:55.711Z
---

```
290. Word PatternEasyGiven a pattern and a string s, find if s&nbsp;follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

&nbsp;
Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true


Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false


Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


&nbsp;
Constraints:


	1 &lt;= pattern.length &lt;= 300
	pattern contains only lower-case English letters.
	1 &lt;= s.length &lt;= 3000
	s contains only lowercase English letters and spaces ' '.
	s does not contain any leading or trailing spaces.
	All the words in s are separated by a single space.

 
```

##Code
 ```
  class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words  = split_string(s);

        unordered_map<char,string> mp;
        unordered_map<string,bool> flag;
        
        if(words.size() != pattern.size())
            return false;
        
        for(int i = 0;i<pattern.size();i++){
            if(mp[pattern[i]] == ""){
                
                if(flag[words[i]] == true)
                    return false;
                flag[words[i]] = true;
                mp[pattern[i]] = words[i];
            }else{
                if(mp[pattern[i]] == words[i]) continue;
                if(mp[pattern[i]] != words[i]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    vector<string> split_string(string s){
        vector<string> ans;
        stringstream str(s);
        string word;
        
        while(str >> word){
            ans.push_back(word);    
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 290-word-pattern
date: 2022-06-25T14:23:55.711Z
---

```
​ 
```
