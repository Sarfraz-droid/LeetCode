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