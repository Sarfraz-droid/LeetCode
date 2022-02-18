class Solution {
public:
    int dp[101][101][601];
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp,-1,sizeof(dp));
        
        int ans = helper(strs,m,n,strs.size()-1);

        return ans < 0 ? 0: ans;
    }
    
    int helper(vector<string>& strs,int m,int n,int pos){
                
        if(m < 0 or n < 0)
        {
            return INT_MIN;
        }else if((m == 0 and n == 0) or pos == -1)
        {
            return 0;
        }
        
        if(dp[m][n][pos] > 0 and dp[m][n][pos] < strs.size())
        {
            return dp[m][n][pos];
        }
        
        
        
        pair<int,int> pr = countZerosandOne(strs[pos]);
        int inlc = 1+ helper(strs,m-pr.first,n-pr.second,pos-1);
        int dinlc =  helper(strs,m,n,pos-1);
        return dp[m][n][pos] = max(inlc,dinlc);
    
    }
    
    pair<int,int> countZerosandOne(string s){
        int zero = 0,one = 0;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0')
                zero++;
            else
                one++;
        }
        
        return {zero,one};
    }
};