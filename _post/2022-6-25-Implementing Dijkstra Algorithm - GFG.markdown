---
layout: post
title: Implementing Dijkstra Algorithm - GFG
date: 2022-06-25T14:23:55.791Z
---

```
# Implementing Dijkstra Algorithm
## Medium 

                Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

&nbsp;

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 9 is 9 - 0 = 9.


&nbsp;

Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.


&nbsp;

Your Task:
You don't need to read input or print anything. Your task is to complete the function&nbsp;dijkstra()&nbsp; which takes number of vertices V and&nbsp;an adjacency list adj as input parameters&nbsp;and returns a list of integers, where ith integer denotes the shortest distance of the ith node from Source node.  Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.

&nbsp;

Expected Time Complexity:&nbsp;O(V2).
Expected Auxiliary Space:&nbsp;O(V2).

&nbsp;

Constraints:
1  ≤  V  ≤  1000
0  ≤  adj[i][j]  ≤  1000

1 ≤&nbsp;adj.size()&nbsp;≤ [ (V*(V - 1)) / 2 ]
0  ≤  S &lt; V
 
             
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
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> st;
        
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto it = st.begin();
            int node = it->second;
            int nodeDist = it->first;
            
            st.erase(it);
            
            for(auto nbr : adj[node])
            {
                int nbrnode = nbr[0];
                int nbrDist = nbr[1];
                
                if(nbrDist + nodeDist < dist[nbrnode]){
                    auto f = st.find({dist[nbrnode],nbrnode});
                    
                    if(f!=st.end()){
                        st.erase(f);
                    }
                    
                    dist[nbrnode] = nbrDist + nodeDist;
                    st.insert({dist[nbrnode],nbrnode});
                    
                }
                
                
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends 
```