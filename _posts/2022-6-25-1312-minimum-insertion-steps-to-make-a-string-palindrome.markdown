---
layout: post
title: 1312-minimum-insertion-steps-to-make-a-string-palindrome
date: 2022-06-25T14:52:08.028Z
---

```
1312. Minimum Insertion Steps to Make a String PalindromeHardGiven a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s&nbsp;palindrome.

A&nbsp;Palindrome String&nbsp;is one that reads the same backward as well as forward.

&nbsp;
Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.


Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".


Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 500
	s consists of lowercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    int minInsertions(string str) {
        
        string s = str;
        reverse(str.begin(),str.end());
        int LPS = LCS(s,str);
        return s.size() - LPS;
    
    }
    
    int LCS(string a,string b){
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    
    for(int i =1;i<=a.size();i++){
        for(int j = 1;j<=b.size();j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[a.size()][b.size()];
}
}; 
```
##NOTES.md
 ---
layout: post
title: 1312-minimum-insertion-steps-to-make-a-string-palindrome
date: 2022-06-25T14:52:08.028Z
---

```
​ 
```
