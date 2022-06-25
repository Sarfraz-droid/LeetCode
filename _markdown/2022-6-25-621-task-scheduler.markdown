---
layout: post
title: 621-task-scheduler
date: 2022-06-25T14:20:30.402Z
---

```
621. Task SchedulerMediumGiven a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer&nbsp;n that represents the cooldown period between&nbsp;two same tasks&nbsp;(the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

&nbsp;
Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -&gt; B -&gt; idle -&gt; A -&gt; B -&gt; idle -&gt; A -&gt; B
There is at least 2 units of time between any two same tasks.


Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.


Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -&gt; B -&gt; C -&gt; A -&gt; D -&gt; E -&gt; A -&gt; F -&gt; G -&gt; A -&gt; idle -&gt; idle -&gt; A -&gt; idle -&gt; idle -&gt; A


&nbsp;
Constraints:


	1 &lt;= task.length &lt;= 104
	tasks[i] is upper-case English letter.
	The integer n is in the range [0, 100].

 
```

##Code
 ```
  class Solution {
public:
    
    static bool cmp(int &a,int &b){
        return a > b;
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> mp;
        for(auto x : tasks){
            mp[x]++;
        }
        
        priority_queue<int> pq;
        
        for(auto x : mp) pq.push(x.second);        
        int time = 0;
        while(!pq.empty()){
            vector<int> tmp;
            
            // output(pq);
            int l = 0;
            
            for(int i = 0;i<=n;i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top()-1);                     
                    pq.pop();
                    l++;
                }
            }            
            for(auto x: tmp){
                if(x>0) pq.push(x);
            }
            
            time += pq.empty() ? l : n+1;
            
        }
        
        return time;
    }
    
    void output(priority_queue<int> pq){
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 621-task-scheduler
date: 2022-06-25T14:20:30.402Z
---

```
​ 
```
