class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        
        for(auto x : s) mp[x]++;
        
        for(auto x : t)
        {
            if(mp[x] <= 0)
                return x;
            mp[x]--;
        }
        return t[s.size()];
    }
};