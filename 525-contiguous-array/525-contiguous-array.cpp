class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int temp = 0;
        int ans = 0;
        int n = nums.size();
        
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            temp += nums[i] == 0 ? -1 : 1;
            
            if(temp == 0)
            {
                ans = max(ans,i+1);
            }
            
            if(mp[temp] == 0){
                mp[temp] = i+1;
            }else{
                ans = max(ans,i+1-mp[temp]);
            }
        }
        
        return ans;
    }
};