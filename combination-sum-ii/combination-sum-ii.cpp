class Solution {
public:
    vector<vector<int>> ans;
    int value;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        value = target;
        
        combinations(temp,candidates,0,0);
        
        return ans;
        
    }
    
    void combinations(vector<int> temp, vector<int>& candidates,int pos,int sum)
    {
        // cout<<sum<<" ";
        if(sum == value)
        {  
            ans.push_back(temp);  
            return;
        }
        
        for(int i = pos;i<candidates.size();i++)
        {
            if(i > pos && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > (value-sum))
                break;
            temp.push_back(candidates[i]);
            combinations(temp,candidates,i+1,sum+candidates[i]);
            temp.pop_back();
        }
    }
    
};