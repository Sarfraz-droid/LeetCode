---
layout: post
title: word-search-ii
date: 2022-06-25T14:28:05.128Z
---

```
212. Word Search IIHardGiven an m x n board&nbsp;of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

&nbsp;
Example 1:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]


Example 2:

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []


&nbsp;
Constraints:


	m == board.length
	n == board[i].length
	1 &lt;= m, n &lt;= 12
	board[i][j] is a lowercase English letter.
	1 &lt;= words.length &lt;= 3 * 104
	1 &lt;= words[i].length &lt;= 10
	words[i] consists of lowercase English letters.
	All the strings of words are unique.

 
```

##Code
 ```
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
```