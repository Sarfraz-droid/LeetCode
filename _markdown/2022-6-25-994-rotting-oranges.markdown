---
layout: post
title: 994-rotting-oranges
date: 2022-06-25T14:20:30.413Z
---

```
994. Rotting OrangesMediumYou are given an m x n grid where each cell can have one of three values:


	0 representing an empty cell,
	1 representing a fresh orange, or
	2 representing a rotten orange.


Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

&nbsp;
Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4


Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


&nbsp;
Constraints:


	m == grid.length
	n == grid[i].length
	1 &lt;= m, n &lt;= 10
	grid[i][j] is 0, 1, or 2.

 
```

##Code
 ```
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
        
        return tot == cnt ? mins : -1;
    }

}; 
```
##NOTES.md
 ---
layout: post
title: 994-rotting-oranges
date: 2022-06-25T14:20:30.413Z
---

```
​ 
```
