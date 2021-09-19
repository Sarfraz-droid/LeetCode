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