class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        deque<int> dp;
        int maxans = INT_MAX;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
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
        
        
        
        return maxans == INT_MAX ? 0 : maxans;
    }
    
    void output(deque<int> vec){
        for(auto x : vec)  cout<<x<<" ";
        cout<<endl;
    }
};