class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minVal = INT_MAX;
        stack<pair<int,int>> st;
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            while(!st.empty() and nums[i] >= st.top().first){
                st.pop();
            }
            
            if(!st.empty() and nums[i] > st.top().second){
                return true;
            }
            
            st.push({nums[i],minVal});
            minVal = min(nums[i],minVal);
        }
        
        
        return false;
    }
};