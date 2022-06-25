---
layout: post
title: search-a-2d-matrix
date: 2022-06-25T14:52:08.149Z
---

```
74. Search a 2D MatrixMediumWrite an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:


	Integers in each row are sorted from left to right.
	The first integer of each row is greater than the last integer of the previous row.


&nbsp;
Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


&nbsp;
Constraints:


	m == matrix.length
	n == matrix[i].length
	1 &lt;= m, n &lt;= 100
	-104 &lt;= matrix[i][j], target &lt;= 104

 
```

##Code
 ```
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[i].size();j++)
            {
                if(matrix[i][j] == target)
                    return true;
            }
        }
    return false;
    }
}; 
```