---
layout: post
title: 207-course-schedule
date: 2022-06-25T14:52:08.046Z
---

```
207. Course ScheduleMediumThere are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.


	For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.


Return true if you can finish all courses. Otherwise, return false.

&nbsp;
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.


Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


&nbsp;
Constraints:


	1 &lt;= numCourses &lt;= 105
	0 &lt;= prerequisites.length &lt;= 5000
	prerequisites[i].length == 2
	0 &lt;= ai, bi &lt; numCourses
	All the pairs prerequisites[i] are unique.

 
```

##Code
 ```
  class Solution {
public:
    bool iscycle(vector<int> adj[], vector<int>& visited, int i)
    {
        
        cout<<i<<" ";
        
        if(visited[i]==2)//explored and no cycle following this node
            return false;
        if(visited[i]==1)//if this node has appeared in the dfs before
            return true;
        visited[i]=1;
        
        for(auto j:adj[i])//all nodes that this nodes leads to
            {
                if(iscycle(adj,visited,j))
                    return true;
            }
        
        visited[i]=2;//node marked explored and no cycle following this node
        return false; 
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];//adjacency matrix for each course
        //indicates which courses require this prereq
        for(auto edge: pre)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited (n,0);//which course node has been visited
        for(int i=0;i<n;i++)//checking if i-th course is a part of/joined to a cycle (dfs)
            {cout<<"\n"<<i<<" ";
            if(iscycle(adj,visited,i))
                return false;}
        return true;
        
    }

}; 
```
##NOTES.md
 ---
layout: post
title: 207-course-schedule
date: 2022-06-25T14:52:08.046Z
---

```
​ 
```
