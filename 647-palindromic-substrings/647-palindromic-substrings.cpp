class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int countSubstrings(string s) {
        n = s.size();
        int count = 0;
        
        dp.resize(n,vector<int>(n));
        
        for(int i = 0;i<n;i++){
            // cout<<en/dl<<"-----\n"<<i<<endl;
            count+=(isPalindrome(i,i,s) + isPalindrome(i,i+1,s));
        }
        
        return count;
    }
    
    int isPalindrome(int l,int r,string &s){            
        int count = 0;
        
        while(l>=0 and r < n){
            string str = s.substr(l,r-l+1);
            // cout<<str<<"\n";
            if(s[l] == s[r] and dp[l][r] == false){
                dp[l][r] = true;
                count++;  
                // cout<<l<<" "<<r<<endl;
            }else
                break;
            
            l--;
            r++;
        }
        // cout<<count<<en/dl;
        return count;
    }
};