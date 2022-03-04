class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
         vector<vector<double>> dp(101,vector<double>(101,0));
        query_row++;
        query_glass++;
        dp[1][1] = poured;
        for(int i = 2;i<=(query_row);i++){
            for(int j = 1;j<=i;j++){
                double sum = 0;
                if(dp[i-1][j] > 1){
                    sum+=double(dp[i-1][j]-1)/2;
                }
                
                if(dp[i-1][j-1] > 1){
                    sum+=double(dp[i-1][j-1]-1)/2;
                }
                dp[i][j] = sum;
            }
        }
        
        return dp[query_row][query_glass] > 1 ? double(1) : dp[query_row][query_glass];
    }
};