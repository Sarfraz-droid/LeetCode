class Solution {
public:
    vector<vector<int>> main;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        subset(nums,0,curr);
        return main;
    }
    
    void subset(vector<int>& nums,int pos,vector<int> curr)
    {
        main.push_back(curr);
        for(int i=pos;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            subset(nums,i+1,curr);
            curr.pop_back();   
        }
    }
    
    
};