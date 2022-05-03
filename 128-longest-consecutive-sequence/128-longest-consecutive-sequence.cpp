class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        
        int prev = INT_MIN;
        
        int temp = 0,ans = 0;
        for(auto it: st){
            
            if(prev == INT_MIN){
                temp++;
                prev = it;
            }else{
                if(it == (prev+1)){
                    temp++;
                    prev++;
                }else{
                    temp = 1;
                    prev = it;
                }
            }
            ans = max(temp,ans);
        }
        
        return ans;
    }
};