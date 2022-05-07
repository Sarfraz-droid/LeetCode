class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        list<int> vec;
        int n = nums.size();
        int count = 0;
        
        for(int i = 0;i<n;i++){
            if(nums[i]%2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        for(int i = 0;i<n;i++){
            sum += nums[i];
            
            if(mp.count(sum-k)){
                count += mp[sum-k];
            }
            
            mp[sum]++;
        }
        
        return count;
    }
};