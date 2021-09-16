class Solution {
public:
    
    void Permuts(vector<vector<int>> &ans,vector<int> comb,vector<int> &nums)
    {
        cout<<nums.size();
        if(nums.size() == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            int k = nums[i];
            nums.erase(nums.begin()+i);
            comb.push_back(k);
            
            Permuts(ans,comb,nums);
            
            comb.pop_back();
            nums.insert(nums.begin()+i,1,k);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        Permuts(ans,comb,nums);
        
        return ans;
    }
};