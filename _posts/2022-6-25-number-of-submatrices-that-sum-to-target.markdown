---
layout: post
title: number-of-submatrices-that-sum-to-target
date: 2022-06-25T14:52:08.142Z
---

```
1074. Number of Submatrices That Sum to TargetHardGiven a matrix&nbsp;and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 &lt;= x &lt;= x2 and y1 &lt;= y &lt;= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate&nbsp;that is different: for example, if x1 != x1'.

&nbsp;
Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.


Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.


Example 3:

Input: matrix = [[904]], target = 0
Output: 0


&nbsp;
Constraints:


	1 &lt;= matrix.length &lt;= 100
	1 &lt;= matrix[0].length &lt;= 100
	-1000 &lt;= matrix[i] &lt;= 1000
	-10^8 &lt;= target &lt;= 10^8

 
```

##Code
 ```
  class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
            int m=matrix.size();
    int n=matrix[0].size();
    
    int count=0;
    
    for(int i=0;i<m;i++){
        
        for(int j=1;j<n;j++){
            
            matrix[i][j]+=matrix[i][j-1];
            
        }
        
    }
    
    for(int c1=0;c1<n;c1++){
        
        for(int c2=c1;c2<n;c2++){
            
            map<int,int>mp;
            mp[0]=1;
            int sum=0;
            
            for(int row=0;row<m;row++){
                
                sum+=matrix[row][c2]-(c1>0?matrix[row][c1-1]:0);
                
                count+=mp[sum-target];
                
                mp[sum]++;
                
            }
        }
    }
    
    return count;
    }
}; 
```