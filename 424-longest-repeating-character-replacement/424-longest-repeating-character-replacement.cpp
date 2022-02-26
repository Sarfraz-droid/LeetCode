class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        int max_cnt = 0,ans = 0;
        
        while(j < s.size()){
            mp[s[j]]++;
            max_cnt = max(max_cnt,mp[s[j]]);
            while((j-i+1) - max_cnt > k){
                mp[s[i]]--;
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    
    }
};