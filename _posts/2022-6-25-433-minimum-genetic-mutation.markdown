---
layout: post
title: 433-minimum-genetic-mutation
date: 2022-06-25T14:20:30.391Z
---

```
433. Minimum Genetic MutationMediumA gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.


	For example, "AACCGGTT" --&gt; "AACCGGTA" is one mutation.


There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

&nbsp;
Example 1:

Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1


Example 2:

Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2


Example 3:

Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
Output: 3


&nbsp;
Constraints:


	start.length == 8
	end.length == 8
	0 &lt;= bank.length &lt;= 10
	bank[i].length == 8
	start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

 
```

##Code
 ```
  class Solution {
public:
    
    vector<string> mutations(string start, string end){
        vector<string> dp;
        
        int n = start.size();
        
        for(int i = 0;i<n;i++){
            if(start[i] != end[i]){
                string str = start;
                str[i] = end[i];
                // cout<<str<<"-"<<end[i]<<"  |  ";
                dp.push_back(str);   
            }
        }
        
        return dp;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<int,string>> q;
        unordered_map<string,bool> mp;
        q.push({0,start});
        
        int count = INT_MAX;
        
        int n = start.size();
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                pair<int,string> f = q.front();
                q.pop();
                mp[f.second] = true;
                for(auto x : bank){
                    int diff = 0;
                    if(mp[x]) continue;
                    
                    for(int i = 0;i<n;i++){
                        if(diff > 1)  break;               
                        if(f.second[i] != x[i])    diff++;
                    }
                    
                    if(diff == 1){
                        if(x == end)                        
                            count = min(count, f.first+1);              
                        else       
                            q.push({f.first+1, x});
                    }
                }
            }
            
        }
        
        return count == INT_MAX ? -1 : count;
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 433-minimum-genetic-mutation
date: 2022-06-25T14:20:30.391Z
---

```
​ 
```
