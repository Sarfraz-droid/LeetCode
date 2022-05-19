class Solution {
public:
    string minWindow(string s, string t) {
        string window = "";
        int t_size = t.size();
        vector<int> hash1(256);
        vector<int> hash2(256);
        
        for(int i = 0;i<t.size();i++){
            hash1[t[i]]++;
        }
        
        string ans = "";
        for(int i = 0;i<s.size();i++){
            
            window.push_back(s[i]);
            hash2[s[i]]++;
            while(window.size() > 0){
                char front = window[0];
                
                if((hash2[front]-1) >= hash1[front]){
                    window.erase(0,1);
                    hash2[front]--;            
                }else{
                    break;
                }
            }
               
            if(compareHash(hash1,hash2)){
                if(ans =="")
                    ans = window;
                else
                    ans = ans.size() < window.size() ? ans : window;
            }
            
            
        }
        
        return  ans;
        
    }
    
    bool compareHash(vector<int>& hash1,vector<int>& hash2){
        for(int i = 0;i<hash1.size();i++){
            if(hash2[i] < hash1[i])
                return false;
        }
        return true;
    }
};