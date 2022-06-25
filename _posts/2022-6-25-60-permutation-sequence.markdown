---
layout: post
title: 60-permutation-sequence
date: 2022-06-25T14:52:08.089Z
---

```
60. Permutation SequenceHardThe set [1, 2, 3, ...,&nbsp;n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:


	"123"
	"132"
	"213"
	"231"
	"312"
	"321"


Given n and k, return the kth permutation sequence.

&nbsp;
Example 1:
Input: n = 3, k = 3
Output: "213"
Example 2:
Input: n = 4, k = 9
Output: "2314"
Example 3:
Input: n = 3, k = 1
Output: "123"

&nbsp;
Constraints:


	1 &lt;= n &lt;= 9
	1 &lt;= k &lt;= n!

 
```

##Code
 ```
  class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> ans = stringtoVec(n);
        k--;
        while(k--){
            next_permutation(ans.begin(),ans.end());
        }
        
        string str = "";
        for(int i = 0;i<ans.size();i++){
            string s = to_string(ans[i]);
            str+=s;
        }
        
        
        return str;
    }
    
    vector<int> stringtoVec(int n){

        
        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(i+1);
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 60-permutation-sequence
date: 2022-06-25T14:52:08.089Z
---

```
​ 
```
