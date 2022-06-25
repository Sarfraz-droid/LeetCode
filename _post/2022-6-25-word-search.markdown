---
layout: post
title: word-search
date: 2022-06-25T14:23:55.862Z
---

```
79. Word SearchMediumGiven an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

&nbsp;
Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true


Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true


Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


&nbsp;
Constraints:


	m == board.length
	n = board[i].length
	1 &lt;= m, n &lt;= 6
	1 &lt;= word.length &lt;= 15
	board and word consists of only lowercase and uppercase English letters.


&nbsp;
Follow up: Could you use search pruning to make your solution faster with a larger board?
 
```

##Code
 ```
  class Solution {
public:
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0] && FindStr(board,word,i,j,0))
                    return true;
            }
        }
        
        return false;
    }
    
    bool FindStr(vector<vector<char>>& board, string word,int i,int j,int len)
    {
        if(len == word.size())
            return true;
        
        if(i<0 || i>=board.size()||j<0 || j>=board[0].size())
        {    
            return false;
        }
        
        if(board[i][j] != word[len])
        {
            return false;    
        }
        
        char temp = board[i][j];
        
        board[i][j] = '*';
        
        len++;
        
        if(FindStr(board,word,i+1,j,len) || FindStr(board,word,i-1,j,len) ||            FindStr(board,word,i,j+1,len) || FindStr(board,word,i,j-1,len))
            return true;
        
        board[i][j] = temp;
        
        return false;
    }
}; 
```