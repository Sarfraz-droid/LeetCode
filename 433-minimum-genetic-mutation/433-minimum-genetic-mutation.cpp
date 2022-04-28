class Solution {
public:
    
    vector<string> mutations(string start, string end){
        vector<string> dp;
        
        int n = start.size();
        
        for(int i = 0;i<n;i++){
            if(start[i] != end[i]){
                string str = start;
                str[i] = end[i];
                // cout<<str<<"-"<<end[i]<<"  |  ";
                dp.push_back(str);   
            }
        }
        
        return dp;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<int,string>> q;
        unordered_map<string,bool> mp;
        q.push({0,start});
        
        int count = INT_MAX;
        
        int n = start.size();
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                pair<int,string> f = q.front();
                q.pop();
                mp[f.second] = true;
                for(auto x : bank){
                    int diff = 0;
                    if(mp[x]) continue;
                    
                    for(int i = 0;i<n;i++){
                        if(diff > 1)  break;               
                        if(f.second[i] != x[i])    diff++;
                    }
                    
                    if(diff == 1){
                        if(x == end)                        
                            count = min(count, f.first+1);              
                        else       
                            q.push({f.first+1, x});
                    }
                }
            }
            
        }
        
        return count == INT_MAX ? -1 : count;
        
    }
};