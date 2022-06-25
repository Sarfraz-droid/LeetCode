---
layout: post
title: ransom-note
date: 2022-06-25T14:52:08.146Z
---

```
383. Ransom NoteEasyGiven two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

&nbsp;
Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

&nbsp;
Constraints:


	1 &lt;= ransomNote.length, magazine.length &lt;= 105
	ransomNote and magazine consist of lowercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        int n = ransomNote.size();
        int m = magazine.size();
        for(int i = 0;i<m;i++)
        {
            mp[magazine[i]]++;
        }
        
        for(int i = 0;i<n;i++)
        {
            cout<<mp[ransomNote[i]]<<" "<<ransomNote[i]<<endl;
            if(mp[ransomNote[i]] == 0)
                return false;
            
            mp[ransomNote[i]]--;
        }
        return true;
    }
}; 
```