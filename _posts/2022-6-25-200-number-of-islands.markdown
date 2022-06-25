---
layout: post
title: 200-number-of-islands
date: 2022-06-25T14:52:08.046Z
---

```
200. Number of IslandsMediumGiven an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

&nbsp;
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


&nbsp;
Constraints:


	m == grid.length
	n == grid[i].length
	1 &lt;= m, n &lt;= 300
	grid[i][j] is '0' or '1'.

 
```

##Code
 ```
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
```
##NOTES.md
 ---
layout: post
title: 200-number-of-islands
date: 2022-06-25T14:52:08.046Z
---

```
​ 
```
