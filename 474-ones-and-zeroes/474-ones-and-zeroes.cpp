class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i<=strs.size();i++){
            pair<int,int> temp = countZerosandOne(strs[i-1]);
            for(int j = 0;j<=m;j++){
                for(int k = 0;k<=n;k++){
                    if(temp.first <= j and temp.second <= k)
                        dp[i][j][k] = max(1 + dp[i-1][j-temp.first][k-temp.second], dp[i-1][j][k]);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        
        return dp[strs.size()][m][n];
        
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