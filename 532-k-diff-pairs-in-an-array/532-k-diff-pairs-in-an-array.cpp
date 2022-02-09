class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(auto x : nums){
            mp[x]++;
        }
        
        int count = 0;
        for(auto x: mp){
            if(k == 0)
            {
                if(x.second > 1)
                    count++;
            }else{
                if(mp.find(x.first + k) != mp.end())
                    count++;
            }
        }
        
        return count;
    }
};