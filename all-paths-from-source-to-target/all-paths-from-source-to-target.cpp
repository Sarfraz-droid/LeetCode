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