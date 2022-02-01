class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return count_rottenEggs(grid);
    }
    
    void display(vector<vector<int>>& grid){
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }
            
            cout<<endl;
        }
    }
    
    int count_rottenEggs(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int tot = 0,cnt = 0;
        int mins = 0;
        for(int i= 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] != 0) tot++;
                
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        
        vector<int> dqx = {-1,+1,0,0};
        vector<int> dqy = {0,0,+1,-1};
        
        
        while(!q.empty()){
            int k = q.size();
            cnt+=k;
            
            while(k--){
                pair<int,int> p = q.front();
                q.pop();
                                
                for(int t = 0;t<4;t++){
                    int nx = p.first + dqx[t];
                    int ny = p.second + dqy[t];
                    
                    if(nx < 0 or nx >= grid.size() or ny < 0 or ny >= grid[0].size() or grid[nx][ny] !=1) continue;
                    
                    grid[nx][ny] = 2;
                    
                    q.push({nx,ny});
                }
            }
            
            if(!q.empty()) mins++;
        }
        
        cout<<tot<<" "<<cnt;
        
        return tot == cnt ? mins : -1;
    }

};