class Solution {
public:
    
    int bit_count(int ans)
    {
        int count = 0;
        
        while(ans > 0)
        {
            if(ans&1)
                count++;
            ans = ans>>1;
        }
        
        cout<<endl;
        return count;
    }
    
    vector<int> countBits(int n) {
        int size = n;
        
        vector<int> ans;
        
        for(int i = 0;i<=n;i++)
        {
            ans.push_back(bit_count(i));
        }
        
        return ans;
    }
};