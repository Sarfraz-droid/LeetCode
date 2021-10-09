class Node{
public:
    string isWord;
    Node* ch[26];
    
    Node()
    {
        isWord = "";
        for(int i = 0;i<26;i++)
            ch[i] = nullptr;
    }
    
};


void BuildTrie(Node* root,vector<string> words)
{
    
    for(string word : words)
    {
        Node* trie = root;
        for(char c : word)
        {
            c -= 'a';
            int k = c;
            
            if(trie->ch[k] == nullptr)
                trie->ch[k] = new Node();
            
            trie = trie->ch[k];
        }
        
        trie->isWord = word;
    }
    
}


class Solution {
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* trie = new Node();
        vector<string> ans;
        
        BuildTrie(trie,words);  
        
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                dfs(board,trie,i,j,ans);
                cout<<endl;
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& board,Node* trie,int i,int j,vector<string>& ans)
    {
        
        char c = board[i][j];
        
        if(c == '*' || trie->ch[c-'a'] == nullptr)
            return;
        // cout<<c<<" ";
        trie = trie->ch[c-'a'];
        
        if(trie->isWord != "")
        {
            // cout<<trie->isWord<<" ";
            ans.push_back(trie->isWord);
            trie->isWord = "";
        }
        
        board[i][j] = '*';
            
        if(i > 0)
            dfs(board,trie,i-1,j,ans);
        if(j > 0)
            dfs(board,trie,i,j-1,ans);
        if(j < board[0].size() -1)
            dfs(board,trie,i,j+1,ans);
        if(i < board.size() - 1)
            dfs(board,trie,i+1,j,ans);
        board[i][j] = c;
        
    }
    
    
    
};