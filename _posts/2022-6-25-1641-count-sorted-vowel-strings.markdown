---
layout: post
title: 1641-count-sorted-vowel-strings
date: 2022-06-25T14:28:04.965Z
---

```
1641. Count Sorted Vowel StringsMediumGiven an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

&nbsp;
Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].


Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.


Example 3:

Input: n = 33
Output: 66045


&nbsp;
Constraints:


	1 &lt;= n &lt;= 50&nbsp;

 
```

##Code
 ```
  class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,1));
        if(n == 1)
            return 5;
        int count = 1;
        for(int i = 1;i<n;i++){
            for(int j = 1;j<5;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if(i == n-1)
                    count+=dp[i][j];
            }
        }
        
        return count;
    }
}; 
```