

class Trie {
public:
    Trie* child[26] = {};
    bool isWord = false;
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* curr = this;
        
        for(int i = 0;i<word.size();i++)
        {
            int c = word[i];
            c -= 'a';
            if(curr->child[c] == nullptr)
                curr->child[c] = new Trie();
            
            curr = curr->child[c];
        }
        curr->isWord = true;
        
    }
    
    bool search(string word) {
        
        Trie* curr = this;
        for(char c : word)
        {
            c-='a';
            if(curr->child[c] == nullptr)
                return false;
            curr = curr->child[c];
        }
        
        if(curr->isWord == true)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        Trie* curr = this;
        for(char c : prefix)
        {
            c-='a';
            if(curr->child[c] == nullptr)
                return false;
            curr = curr->child[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */