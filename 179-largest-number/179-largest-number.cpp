class Solution {
public:
    
    static bool cmp(int &a,int &b){
        string cha = to_string(a);
        string chb = to_string(b);
        
        return cha+chb > chb+cha;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        
        string ans;
        for(auto x : nums){
            ans+= to_string(x);
        }
        
        cout<<ans;
        while(!ans.empty() and ans[0] == '0'){
            ans.erase(ans.begin());
            
        }
            
        return ans.size() == 0 ? "0": ans;
    }
};