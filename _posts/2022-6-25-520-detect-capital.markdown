---
layout: post
title: 520-detect-capital
date: 2022-06-25T14:52:08.069Z
---

```
520. Detect CapitalEasyWe define the usage of capitals in a word to be right when one of the following cases holds:


	All letters in this word are capitals, like "USA".
	All letters in this word are not capitals, like "leetcode".
	Only the first letter in this word is capital, like "Google".


Given a string word, return true if the usage of capitals in it is right.

&nbsp;
Example 1:
Input: word = "USA"
Output: true
Example 2:
Input: word = "FlaG"
Output: false

&nbsp;
Constraints:


	1 &lt;= word.length &lt;= 100
	word consists of lowercase and uppercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        if(word[0] >= 'A' and word[0] <= 'Z'){
            if(word[1] >= 'A' and word[1] <= 'Z'){
                for(int i = 2;i<word.size();i++){
                    if(word[i] >='a' and word[i] <= 'z')
                        return false;
                }
                
                return true;
            }else{
                for(int i = 2;i<word.size();i++){
                    if(word[i] >= 'A' and word[i] <= 'Z')
                        return false;
                }
                
                return true;
            }
        }else{
            for(int i = 1;i<word.size();i++){
                if(word[i] >= 'A' and word[i]<= 'Z')
                    return false;
            }
            
            return true;
        }
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 520-detect-capital
date: 2022-06-25T14:52:08.069Z
---

```
​ 
```
