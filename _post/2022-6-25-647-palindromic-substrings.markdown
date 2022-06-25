---
layout: post
title: 647-palindromic-substrings
date: 2022-06-25T14:23:55.777Z
---

```
647. Palindromic SubstringsMediumGiven a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

&nbsp;
Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 1000
	s consists of lowercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int countSubstrings(string s) {
        n = s.size();
        int count = 0;
        
        dp.resize(n,vector<int>(n));
        
        for(int i = 0;i<n;i++){
            // cout<<en/dl<<"-----\n"<<i<<endl;
            count+=(isPalindrome(i,i,s) + isPalindrome(i,i+1,s));
        }
        
        return count;
    }
    
    int isPalindrome(int l,int r,string &s){            
        int count = 0;
        
        while(l>=0 and r < n){
            string str = s.substr(l,r-l+1);
            // cout<<str<<"\n";
            if(s[l] == s[r] and dp[l][r] == false){
                dp[l][r] = true;
                count++;  
                // cout<<l<<" "<<r<<endl;
            }else
                break;
            
            l--;
            r++;
        }
        // cout<<count<<en/dl;
        return count;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 647-palindromic-substrings
date: 2022-06-25T14:23:55.777Z
---

```
​ 
```
