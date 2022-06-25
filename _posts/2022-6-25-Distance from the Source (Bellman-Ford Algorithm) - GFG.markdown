---
layout: post
title: Distance from the Source (Bellman-Ford Algorithm) - GFG
date: 2022-06-25T14:52:08.102Z
---

```
# Distance from the Source (Bellman-Ford Algorithm)
## Medium 

                Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.
&nbsp;

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.


Example 2:

Input:

S = 2
Output:
1 6 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-0. This has a distance of 1.
For nodes 2 to 1, we cam follow the path-
2-0-1, which has a distance of 1+5 = 6,


&nbsp;

Your Task:
You don't need to read input or print anything. Your task is to complete the function bellman_ford()&nbsp; which takes number of vertices V and an E sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w as input parameters and returns a list of integers where the ith integer denotes the distance of ith node from source node. If some node isn't possible to visit, then it's distance should be 100000000(1e8).

&nbsp;

Expected Time Complexity:&nbsp;O(V*E).
Expected Auxiliary Space:&nbsp;O(V).

&nbsp;

Constraints:
1  ≤  V  ≤ 500
1  ≤ E  ≤ V*(V-1)
-1000  ≤  adj[i][j]  ≤  1000
0  ≤  S &lt; V
 
             
```

##Code
 ```
  // { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int n, vector<vector<int>> adj, int S) {
        // Code here
        
        vector<int> dist(n,1e8);
        dist[S] = 0;
        for(int i =0;i<(n-1);i++){
            for(auto e : adj){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                
                dist[v] = min(dist[v],w + dist[u]);
            }
        }
        
        return dist;
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
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends 
```