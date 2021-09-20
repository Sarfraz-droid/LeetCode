class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i = 0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        for(int i = 0;i<n;i++)
        {
            if(mp[t[i]] == 0)
                return false;
            
            mp[t[i]]--;
        }
        return true;
    }
};