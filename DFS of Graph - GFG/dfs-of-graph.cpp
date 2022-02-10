// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> vis;
    vector<int> ans;
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vis.resize(V);
        
        vis[0] = true;
        dfs(0,adj);
        
        return ans;
    }
    
    void dfs(int i,vector<int> adj[]){
        ans.push_back(i);
        // cout<<i<<" ";
        for(auto x : adj[i]){
            // cout<<x<<" ";
            if(vis[x])
                continue;
            else{
                vis[x] = true;
                dfs(x,adj);
            }
        }
        
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends