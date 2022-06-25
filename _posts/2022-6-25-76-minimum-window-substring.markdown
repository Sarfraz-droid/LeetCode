---
layout: post
title: 76-minimum-window-substring
date: 2022-06-25T14:52:08.095Z
---

```
76. Minimum Window SubstringHardGiven two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

&nbsp;
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.


Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


&nbsp;
Constraints:


	m == s.length
	n == t.length
	1 &lt;= m, n&nbsp;&lt;= 105
	s and t consist of uppercase and lowercase English letters.


&nbsp;
Follow up: Could you find an algorithm that runs in O(m + n) time? 
```

##Code
 ```
  class Solution {
public:
    string minWindow(string s, string t) {
        string window = "";
        int t_size = t.size();
        vector<int> hash1(256);
        vector<int> hash2(256);
        
        for(int i = 0;i<t.size();i++){
            hash1[t[i]]++;
        }
        
        string ans = "";
        int w_size = 0;
        for(int i = 0;i<s.size();i++){
            
            window.push_back(s[i]);
            hash2[s[i]]++;
            w_size++;
            
            if(w_size < t_size){
                continue;
            }
            while(w_size > 0){
                char front = window[0];
                
                if((hash2[front]-1) >= hash1[front]){
                    window.erase(0,1);
                    hash2[front]--;     
                    w_size--;
                }else{
                    break;
                }
            }
               
            if(compareHash(hash1,hash2)){
                if(ans =="")
                    ans = window;
                else
                    ans = ans.size() < w_size ? ans : window;
            }
            
            
        }
        
        return  ans;
        
    }
    
    bool compareHash(vector<int>& hash1,vector<int>& hash2){
        for(int i = 0;i<hash1.size();i++){
            if(hash2[i] < hash1[i])
                return false;
        }
        return true;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 76-minimum-window-substring
date: 2022-06-25T14:52:08.095Z
---

```
​ 
```
