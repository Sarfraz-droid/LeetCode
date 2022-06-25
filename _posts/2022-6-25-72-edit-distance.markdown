---
layout: post
title: 72-edit-distance
date: 2022-06-25T14:20:30.404Z
---

```
72. Edit DistanceHardGiven two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:


	Insert a character
	Delete a character
	Replace a character


&nbsp;
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -&gt; rorse (replace 'h' with 'r')
rorse -&gt; rose (remove 'r')
rose -&gt; ros (remove 'e')


Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -&gt; inention (remove 't')
inention -&gt; enention (replace 'i' with 'e')
enention -&gt; exention (replace 'n' with 'x')
exention -&gt; exection (replace 'n' with 'c')
exection -&gt; execution (insert 'u')


&nbsp;
Constraints:


	0 &lt;= word1.length, word2.length &lt;= 500
	word1 and word2 consist of lowercase English letters.

 
```

##Code
 ```
  class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int ans = findDist(word1,word2,0,0);
        return ans;
    }
    
    int findDist(string word1,string word2,int i,int j){
        
        
        
        if(i == word1.size())
        {
            return word2.size()-j;
        }
        
        if(j == word2.size()){
            return word1.size() -i;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = 1e3+7;
        if(word1[i]==word2[j])
        {
            ans = findDist(word1,word2,i+1,j+1);
        }
        else
        {
            int opt1 = 1+findDist(word1,word2,i,j+1); //Insert
            int opt2 = 1+findDist(word1,word2,i+1,j); //Delete
            int opt3 = 1+findDist(word1,word2,i+1,j+1); //Replace
            ans = min({opt1, opt2, opt3});
        }
        return dp[i][j] = ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 72-edit-distance
date: 2022-06-25T14:20:30.404Z
---

```
​ 
```
