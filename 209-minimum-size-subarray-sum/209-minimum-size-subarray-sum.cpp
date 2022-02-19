class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        deque<int> dp;
        int maxans = INT_MAX;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            // output(dp);
            sum+=nums[i];
            dp.push_back(nums[i]);
            
            if(sum >= target)
            {
                maxans = dp.size() < maxans ? dp.size() : maxans;
                while(sum >= target and !dp.empty()){
                    sum-= dp[0];
                    dp.pop_front();
                    
                    if(sum >= target){
                        maxans = dp.size() < maxans ? dp.size() : maxans;
                    }
                }
            }
        }
        
        
        // output(dp);
        
        return maxans == INT_MAX ? 0 : maxans;
    }
    
    void output(deque<int> vec){
        for(auto x : vec)  cout<<x<<" ";
        cout<<endl;
    }
};