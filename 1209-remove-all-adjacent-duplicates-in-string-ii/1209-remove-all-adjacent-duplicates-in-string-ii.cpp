class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> vec;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(vec.empty() || s[i] != vec.back().first) {
                vec.push_back({s[i],1});
            }else if(++vec.back().second == k){
                vec.pop_back();
            }
        }
        
        string str = "";
        
        for(int i = 0;i<vec.size();i++){
            while(vec[i].second--){
                str.push_back(vec[i].first);
            }
            
            
        }
        
        
        return str;
    }
};