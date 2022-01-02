class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        
        for(int i = 0;i<time.size();i++)
        {
            cout<<time[i]%60<<" ";
            mp[time[i]%60]++;
        }
        
        cout<<endl;
        
        int counts = 0;
        
        for(auto x: mp)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        
        for(int i = 0;i<30;i++){
            if(i==0)
            {
                
                counts+=(mp[i]*(mp[i]-1))/2;
            }else{
                cout<<i<<" "<<mp[i]*mp[60-i]<<" \n";
                counts+=mp[i]*mp[60-i];
            }
                    
        }
        
        counts+= (mp[30]*(mp[30]-1))/2;
        
        return counts;
    }
};