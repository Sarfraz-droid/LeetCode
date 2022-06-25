---
layout: post
title: 37-sudoku-solver
date: 2022-06-25T14:28:04.985Z
---

```
37. Sudoku SolverHardWrite a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:


	Each of the digits 1-9 must occur exactly once in each row.
	Each of the digits 1-9 must occur exactly once in each column.
	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.


The '.' character indicates empty cells.

&nbsp;
Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation:&nbsp;The input board is shown above and the only valid solution is shown below:




&nbsp;
Constraints:


	board.length == 9
	board[i].length == 9
	board[i][j] is a digit or '.'.
	It is guaranteed that the input board has only one solution.

 
```

##Code
 ```
  class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            //if it has blank space
            if(board[i][j] == '.')
            {
                for(char c='1' ; c<='9' ;c++)
                {
                    if(isValid(board,i,j,c))
                    {
                        board[i][j] = c;
                        if(solve(board)==true)//if we found answer then no need further
                           return true;
                        else
                            board[i][j] = '.';//else removing the char value
                    }
                }
                return false; //tho its empty but we cant enter any value return false
            }
        }
    }
    return true;
    }

bool isValid(vector<vector<char>>& board,int row,int col, char c)
{
    for(int i=0;i<board.size();i++)
    {
        //for val check in row, row is stable
        if(board[row][i] == c)
        {
            return false;
        }
        //for val check in col, col is stable
        if(board[i][col] == c)
        {
            return false;
        }
        //for the 3x3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c)
        {
            return false;
        }
    }
    return true;
}
}; 
```