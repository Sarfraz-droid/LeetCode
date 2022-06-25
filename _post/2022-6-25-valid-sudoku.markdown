---
layout: post
title: valid-sudoku
date: 2022-06-25T14:23:55.861Z
---

```
36. Valid SudokuMediumDetermine if a&nbsp;9 x 9 Sudoku board&nbsp;is valid.&nbsp;Only the filled cells need to be validated&nbsp;according to the following rules:


	Each row&nbsp;must contain the&nbsp;digits&nbsp;1-9 without repetition.
	Each column must contain the digits&nbsp;1-9&nbsp;without repetition.
	Each of the nine&nbsp;3 x 3 sub-boxes of the grid must contain the digits&nbsp;1-9&nbsp;without repetition.


Note:


	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
	Only the filled cells need to be validated according to the mentioned&nbsp;rules.


&nbsp;
Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true


Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


&nbsp;
Constraints:


	board.length == 9
	board[i].length == 9
	board[i][j] is a digit or '.'.

 
```

##Code
 ```
  class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size()/3;
        // for(int i = 0;i<board.size();i++)
        // {
        //     for(int j = 0;j<board.size();j++)
        //     {
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i = 0;i<board.size();i++)
        {
            unordered_map<char,int> mp;
            for(int j = 0;j<board.size();j++)
            {
                if(board[j][i] != '.')
                {
                    mp[board[j][i]]++;
                    if(mp[board[j][i]] > 1)
                    {
                        cout<<"Horizontal false";
                        return false;
                    }
                }
            }
            mp.clear();
        }

        for(int i = 0;i<board.size();i++)
        {
            unordered_map<char,int> mp;
            for(int j = 0;j<board.size();j++)
            {
                if(board[i][j] != '.')
                {
                    mp[board[i][j]]++;
                    if(mp[board[i][j]] > 1)
                    {
                        cout<<"Vertical false";
                        return false;
                    }
                }
            }
            mp.clear();
        }
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(!check(board,i,j))
                    return false;
            }
        }
        return true;
    }
    
    bool check(vector<vector<char>>& board,int n,int m)
    {
        unordered_map<char,int> mp;
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                // cout<<board[i+3*n][j+3*m]<<" ";
                if(board[i+3*n][j+3*m] != '.')
                {
                    mp[board[i+3*n][j+3*m]]++;
                    if(mp[board[i+3*n][j+3*m]] > 1)
                    {
                        return false;              
                    }
                }
            }
            cout<<endl;
        }
        return true;
    }
        
    
    
}; 
```