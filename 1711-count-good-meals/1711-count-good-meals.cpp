class Solution {
public:
    int mod = 1e9 + 7;
    int countPairs(vector<int>& num) {
        
        int count = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0;i<num.size();i++){
            mp[num[i]]++;
        }
        
        for(int i = 0;i<num.size();i++){
            mp[num[i]]--;
            int k =  1;
            for(int j = 0;j<=21;j++){
                
                if(mp[k-num[i]] != 0)
                {    
                    count= (count + mp[k-num[i]])%mod;
                }
                k = k<<1;
            }
            
            
            
        }
        
        return count%mod;
    }

};