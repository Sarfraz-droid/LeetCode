---
layout: post
title: all-paths-from-source-to-target
date: 2022-06-25T14:52:08.122Z
---

```
797. All Paths From Source to TargetMediumGiven a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

&nbsp;
Example 1:

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -&gt; 1 -&gt; 3 and 0 -&gt; 2 -&gt; 3.


Example 2:

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]


Example 3:

Input: graph = [[1],[]]
Output: [[0,1]]


Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]


Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]


&nbsp;
Constraints:


	n == graph.length
	2 &lt;= n &lt;= 15
	0 &lt;= graph[i][j] &lt; n
	graph[i][j] != i (i.e., there will be no self-loops).
	All the elements of graph[i] are unique.
	The input graph is guaranteed to be a DAG.

 
```

##Code
 ```
  class Solution {
public:
    vector<vector<int>> ans;
    
    void sum(vector<vector<int>> graph,int n,int index,vector<int> res,int last)
    {
        if(last == n-1)
        {
            if(find(ans.begin(),ans.end(),res) == ans.end())
                ans.push_back(res);
            return;
        }
        
        for(auto x : graph[index])
        {
            if(find(res.begin(),res.end(),x) != res.end())
                sum(graph,n,x,res,x);
            else
            {
                res.push_back(x);                   
                sum(graph,n,x,res,x);
                res.pop_back();
            }


        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<int> res;
        res.push_back(0);
        sum(graph,graph.size(),0,res,0);


        
        return ans;
        
    }
}; 
```