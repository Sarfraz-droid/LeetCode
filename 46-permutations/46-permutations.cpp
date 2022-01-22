class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        ans.clear();
        vector<bool> flag(n);
        vector<int> curr;   
        findPermutations(nums,curr,flag,n);
               
        return ans;
    }
    
    void findPermutations(vector<int>& nums,vector<int> curr,vector<bool>& flag,int n){
        if(n == curr.size()){
            ans.push_back(curr);
        }
        
        for(int i = 0;i<n;i++){
            if(flag[i]) continue;
            
            flag[i] = true;
            curr.push_back(nums[i]);
            findPermutations(nums,curr,flag,n);
            curr.pop_back();
            flag[i] = false;
        }
    }
};