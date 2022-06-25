---
layout: post
title: reshape-the-matrix
date: 2022-06-25T14:52:08.147Z
---

```
566. Reshape the MatrixEasyIn MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

&nbsp;
Example 1:

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]


Example 2:

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]


&nbsp;
Constraints:


	m == mat.length
	n == mat[i].length
	1 &lt;= m, n &lt;= 100
	-1000 &lt;= mat[i][j] &lt;= 1000
	1 &lt;= r, c &lt;= 300

 
```

##Code
 ```
  class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int i = 0,j = 0;
        vector<vector<int>> vec(r,vector<int>(c));
        
        if(mat.size()*mat[0].size() !=  r*c)
            return mat;
        
        for(int m = 0;m<mat.size();m++)
        {
            for(int n = 0;n<mat[0].size();n++)
            {
                if(j == c)
                {
                    i++;
                    j = 0;
                }
                    
                vec[i][j] = mat[m][n];
                j++;
            }
                
        }
        
        return vec;
    }
}; 
```