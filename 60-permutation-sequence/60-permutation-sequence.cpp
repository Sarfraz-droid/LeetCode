class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> ans = stringtoVec(n);
        k--;
        while(k--){
            next_permutation(ans.begin(),ans.end());
        }
        
        string str = "";
        for(int i = 0;i<ans.size();i++){
            string s = to_string(ans[i]);
            str+=s;
        }
        
        
        return str;
    }
    
    vector<int> stringtoVec(int n){

        
        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(i+1);
        }
        
        return ans;
    }
};