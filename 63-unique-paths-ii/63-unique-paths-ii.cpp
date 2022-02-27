class Solution {
public:
    int ans;
    int m,n;
    int dp[100][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ans = 0;
        memset(dp,0,sizeof(dp));
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return helper(obstacleGrid,0,0);
    }
    
    int helper(vector<vector<int>>& obstacleGrid,int i,int j){

        if(i>=m or j >= n)
        {
            return 0;
        }
        
               
        if(obstacleGrid[i][j] == 1)
            return 0;
        
        if(i == m-1 and j == n-1)
        {    
            ans++;
            return 1;
        }
        
        
        if(dp[i][j] != 0){
            return dp[i][j];    
        }
 
        
        return dp[i][j] = helper(obstacleGrid,i+1,j) + helper(obstacleGrid,i,j+1);
        
    }
};