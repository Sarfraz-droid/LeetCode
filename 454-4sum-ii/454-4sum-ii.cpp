class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> mp;
        int ans = 0;
        
        for(auto x: nums1){
            for(auto y: nums2){
                mp[x+y]++;
            }
        }
        int count = 0;
        for(auto x: nums3){
            for(auto y: nums4){
                count+= mp[0-(x+y)];
            }
        }

        return count;
    }
};