class Solution {
public:
    int minsum;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        minsum = INT_MAX;
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int l = (j-1) >= 0 ? matrix[i-1][j-1] : INT_MAX;
                int c = matrix[i-1][j];
                int r = (j+1 < n) ? matrix[i-1][j+1] : INT_MAX;
                
                matrix[i][j] += min(l, min(c,r));
            }
        }
        
        for(int j = 0;j<n;j++)
        {
            minsum = min(minsum,matrix[n-1][j]);
        }
        
        return minsum;
    }
    
    int findPaths(vector<vector<int>>& matrix,int i,int j,int n,int sum,vector<vector<int>>& dp)
    {
        if(j<0 || j>=n || i < 0)
            return INT_MAX;
        
        if(i == n)
        {
            minsum = min(sum,minsum);
            return sum;
        }
        
        sum+=matrix[i][j];
        
        return dp[i][j] = min(findPaths(matrix,i+1,j+1,n,sum,dp),min(findPaths(matrix,i+1,j-1,n,sum,dp),findPaths(matrix,i+1,j,n,sum,dp)));
    }
};