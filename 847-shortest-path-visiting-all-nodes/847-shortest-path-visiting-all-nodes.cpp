class Solution {
public:
    
    int solve(vector<vector<int>>&g){
        int n=g.size(); // Total n nodes from 0 to n-1
        // Let us suppose --> 
        /*
            We have 4 nodes : (labelled 0 to 3)
            if we have visited all nodes then all bits are set to 1.
            2^4 - 1 = 10000 - 1 = 1111 (ALL BITS ARE SET MEANS ALL 4 NODES(0 to 3) ARE VISITED)
            so at the end whenever our mask is equal to all (i.e mask == all) then we should return the answer.     
        */
        // instead of maintaining visited vector or set we will use bitmasking, because it will not give us TLE
        int all = (1 << n) - 1; // when we have visited all the nodes then our mask is equal to "all"
        queue<pair<int , pair<int, int>>>q; // { ith Node ,{dist, mask for keeping record of visited nodes from ith node}}
        set<pair<int, int>>vis;   // {ith node, mask}
        //initialization of queue
        for(int i=0;i<n;i++)
        {
            int mask = (1<<i); // 2^i 
            /* suppose for 4 nodes (0 to 3) :
                2^0 = 1 = 1
                2^1 = 2 = 10
                2^2 = 4 = 100
                2^3 = 8 = 1000
            */       
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        
        // BFS
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int val = node.first , dist = node.second.first , mask = node.second.second;
            // explore its all neighbours
            for(auto nbr : g[val]){
                int newMask = (mask | (1<<nbr)); 
                // mask of node 0 - 0001
                // mask of node 1 - 0010
                // result of above 2 masks by doing bitwise OR = 0011 (2 set bits means 2 nodes (i.e 0th and 1st are visited))  
                if(newMask == all)
                    return dist+1; // distance comes first will be the promised shortest path length because of BFS algo.
                else if(vis.count({nbr, newMask})){
                    continue; // already visited so skip this
                }
                else{
                    q.push({nbr,{dist+1,newMask}});
                    vis.insert({nbr, newMask});               
                }
            }
        }
        return 0;
    }
    
    // Best questions on BFS - intelligent bfs --- modified BFS
    // What if there is a way, in which we can visit the same node again and still avoid cycle. lets call this type of bfs as intelligent bfs.
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n=graph.size();
        if(n==1) 
            return 0;
        
        return solve(graph);
    }
};