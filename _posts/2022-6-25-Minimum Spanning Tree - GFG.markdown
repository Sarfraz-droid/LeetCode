---
layout: post
title: Minimum Spanning Tree - GFG
date: 2022-06-25T14:20:30.416Z
---

```
# Minimum Spanning Tree
## Medium 

                Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the&nbsp;Minimum Spanning Tree.

&nbsp;

Example 1:

Input:

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.


Example 2:

Input:

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.


&nbsp;

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function&nbsp; spanningTree() which takes number of vertices V and&nbsp;an adjacency matrix adj as input parameters&nbsp;and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0]&nbsp;denotes that there is an edge between i and a[i][0]&nbsp;and second integer a[i][1]&nbsp;denotes that the distance between edge i and a[i][0] is a[i][1].

Expected Time Complexity:&nbsp;O(ElogV).
Expected Auxiliary Space:&nbsp;O(V2).
&nbsp;

Constraints:
2  ≤  V ≤  1000
V-1 ≤  E  ≤  (V*(V-1))/2
1  ≤  w  ≤  1000
Graph is connected and&nbsp;doesn't contain self loops &amp;&nbsp;multiple edges.
 
             
```

##Code
 ```
  // { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        //Brute Force O((N+E)log(N))
        //optimal sol O(NlogN)
        
        // int par[V];
        int key[V];
        bool mst[V];
        
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX,mst[i]=false;
        }
        
        key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({key[0],0});  //key[],weight
        
        while(!pq.empty())
        {
            int u=pq.top().second;   //edge u-->v
            pq.pop();
            
            mst[u]=true;
            for(auto it:adj[u])
            {
                int v=it[0];
                int wt=it[1];
                
                if(mst[v]==false and wt<key[v])
                {
                    key[v]=wt;
                    pq.push({key[v],v});
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=key[i];
        }
        return sum;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends 
```