class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp(n+1);
        
        for(int i =0;i<n;i++){
            if(nums[i] <= n){
                temp[nums[i]]++;
            }
        }
        
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            if(temp[i] == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};