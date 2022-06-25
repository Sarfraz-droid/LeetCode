---
layout: post
title: counting-bits
date: 2022-06-25T14:52:08.128Z
---

```
338. Counting BitsEasyGiven an integer n, return an array ans of length n + 1 such that for each i (0 &lt;= i &lt;= n), ans[i] is the number of 1's in the binary representation of i.

&nbsp;
Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10


Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101


&nbsp;
Constraints:


	0 &lt;= n &lt;= 105


&nbsp;
Follow up:


	It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
	Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

 
```

##Code
 ```
  class Solution {
public:
    
    int bit_count(int ans)
    {
        int count = 0;
        
        while(ans > 0)
        {
            if(ans&1)
                count++;
            ans = ans>>1;
        }
        
        cout<<endl;
        return count;
    }
    
    vector<int> countBits(int n) {
        int size = n;
        
        vector<int> ans;
        
        for(int i = 0;i<=n;i++)
        {
            ans.push_back(bit_count(i));
        }
        
        return ans;
    }
}; 
```