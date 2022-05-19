class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int l = 0,r = 0;
        int zero_count = 0;
        
        while(r < nums.size()){
            
            if(nums[r] == 0)
                zero_count++;
            r++;
            while(zero_count > k){
                if(nums[l] == 0)
                    zero_count--;
                l++;
            }
            
            ans = max(ans,r-l);
        }
        
        return ans;
    }
};