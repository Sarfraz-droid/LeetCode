class Solution {
public:
    
    
    void findComb(vector<int> candidates,int target,vector<vector<int>>& ans,vector<int> comb,int k)
    {
        int sum = accumulate(comb.begin(),comb.end(),0);
        if(sum == target)
            ans.push_back(comb);
        else if(sum > target)
            return;
        
        for(int i = k;i<candidates.size();i++)
        {
            comb.push_back(candidates[i]);
            findComb(candidates,target,ans,comb,i);
            comb.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> comb;
        findComb(candidates,target,ans,comb,0);
        
        return ans;
    }
};