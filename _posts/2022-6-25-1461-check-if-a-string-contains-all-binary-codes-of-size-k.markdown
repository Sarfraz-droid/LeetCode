---
layout: post
title: 1461-check-if-a-string-contains-all-binary-codes-of-size-k
date: 2022-06-25T14:52:08.034Z
---

```
1461. Check If a String Contains All Binary Codes of Size KMediumGiven a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

&nbsp;
Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.


Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 


Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 5 * 105
	s[i] is either '0' or '1'.
	1 &lt;= k &lt;= 20

 
```

##Code
 ```
  class Solution {
public:
    
    string inttostring(int num,int k){
        string ans;
        for(int i = 0;i<k;i++){
            ans += num%2 ? "0" : "1";
            num = num>>1;
        }
        
        return ans;
    }
    
    bool hasAllCodes(string s, int k) {
        set<string> st;
        
        if(k > s.size())
            return false;
        
        for(int i = 0;i<=s.size()-k;i++){
            
            st.insert(s.substr(i,k));
        }
        
        for(auto x : st){
            cout<<x<<" ";
        }
        
        
        return st.size() == 2<<(k-1);
    }
    
}; 
```