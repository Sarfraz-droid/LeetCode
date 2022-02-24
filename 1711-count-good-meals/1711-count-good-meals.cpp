class Solution {
public:
    
    int countPairs(vector<int>& num) {
        int mod = 1e9 + 7;
        
        int count = 0;
        unordered_map<int,int> mp;
        
        int n = num.size();
        
        for(int i = 0;i<n;i++){
            mp[num[i]]++;
        }
        
        for(int i = 0;i<n;i++){
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