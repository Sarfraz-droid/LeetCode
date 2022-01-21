class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> temp_ans;
        vector<int> curr;
        
        sort(nums.begin(),nums.end());
        SubsetSum(0,nums,temp_ans,curr);

        return vector<vector<int>>(temp_ans.begin(),temp_ans.end());
    }
    
    void SubsetSum(int pos,vector<int>& nums,set<vector<int>>& ans,vector<int>& curr){
        ans.insert(curr);
        
        for(int i = pos;i<nums.size();i++){
            curr.push_back(nums[i]);
            SubsetSum(i+1,nums,ans,curr);
            curr.pop_back();
        }
    }
};