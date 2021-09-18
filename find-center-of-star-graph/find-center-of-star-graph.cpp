class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(auto e : edges)
        {
            mp[e[0]]++;
            mp[e[1]]++;            
        }
        int ans = INT_MIN;
        int curr = 0;
        for(auto x : mp)
        {
            if(x.second > curr)
            {
                ans = x.first;
                curr = x.second;
            }
        }
        return ans;
    }
};