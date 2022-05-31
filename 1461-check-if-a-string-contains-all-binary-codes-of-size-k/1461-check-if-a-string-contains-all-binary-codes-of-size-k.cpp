class Solution {
public:
    
    string inttostring(int num,int k){
        string ans;
        for(int i = 0;i<k;i++){
            ans += num%2 ? "0" : "1";
            num = num>>1;
        }
        
        return ans;
    }
    
    bool hasAllCodes(string s, int k) {
        set<string> st;
        
        if(k > s.size())
            return false;
        
        for(int i = 0;i<=s.size()-k;i++){
            
            st.insert(s.substr(i,k));
        }
        
        for(auto x : st){
            cout<<x<<" ";
        }
        
        
        return st.size() == 2<<(k-1);
    }
    
};