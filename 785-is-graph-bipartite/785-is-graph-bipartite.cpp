class Solution {
public:
    int n;
    // vector<bool> visited;
    vector<int> col;
    bool helper(vector<vector<int>>& graph,int pos){
        queue<int> q;
        q.push(pos);

        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto nbr : graph[f]){
                if(col[nbr] == -1){
                    col[nbr] = col[f] == 0 ? 1 : 0;
                    q.push(nbr);
                }else if(col[nbr] == col[f]){
                    return false;
                }
            }
        }
        
        return true;
    }

    
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        col.resize(n,-1);
        
        for(int i = 0;i<n;i++){
            if(col[i] == -1 and graph[i].size() > 0){
                col[i] = 0;
                if(!helper(graph,i)){
                    return false;
                }
            }
        }
        
        return true;
    }
};