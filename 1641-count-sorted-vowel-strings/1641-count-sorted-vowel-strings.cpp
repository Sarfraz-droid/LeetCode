class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,1));
        if(n == 1)
            return 5;
        int count = 1;
        for(int i = 1;i<n;i++){
            for(int j = 1;j<5;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if(i == n-1)
                    count+=dp[i][j];
            }
        }
        
        return count;
    }
};