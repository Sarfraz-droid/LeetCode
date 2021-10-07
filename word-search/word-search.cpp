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