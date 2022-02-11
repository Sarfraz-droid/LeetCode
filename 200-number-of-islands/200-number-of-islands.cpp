class Solution {
public:
    
    void markCurrent(int i,int j,vector<vector<char>>& grid){
        if(i>= 0 and j>=0 and j<grid[0].size() and i < grid.size() and grid[i][j] == '1'){
            grid[i][j] = '2';
            
            markCurrent(i+1,j,grid);
            markCurrent(i-1,j,grid);
            markCurrent(i,j+1,grid);
            markCurrent(i,j-1,grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    // cout<<i<<" "<<j<<endl;
                    markCurrent(i,j,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};