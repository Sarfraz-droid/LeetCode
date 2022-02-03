class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp_s(26);
        
        vector<int> mp_t(26);
        
        for(auto ch: s){
            mp_s[ch-'a']++;
        }
        
        for(auto ch:t){
            mp_t[ch-'a']++;
        }
        
        return mp_s == mp_t;
    }
};