class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words  = split_string(s);

        unordered_map<char,string> mp;
        unordered_map<string,bool> flag;
        
        if(words.size() != pattern.size())
            return false;
        
        for(int i = 0;i<pattern.size();i++){
            if(mp[pattern[i]] == ""){
                
                if(flag[words[i]] == true)
                    return false;
                flag[words[i]] = true;
                mp[pattern[i]] = words[i];
            }else{
                if(mp[pattern[i]] == words[i]) continue;
                if(mp[pattern[i]] != words[i]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    vector<string> split_string(string s){
        vector<string> ans;
        stringstream str(s);
        string word;
        
        while(str >> word){
            ans.push_back(word);    
        }
        
        return ans;
    }
};