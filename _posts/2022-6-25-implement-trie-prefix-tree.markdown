---
layout: post
title: implement-trie-prefix-tree
date: 2022-06-25T14:20:30.449Z
---

```
208. Implement Trie (Prefix Tree)MediumA trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:


	Trie() Initializes the trie object.
	void insert(String word) Inserts the string word into the trie.
	boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
	boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


&nbsp;
Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


&nbsp;
Constraints:


	1 &lt;= word.length, prefix.length &lt;= 2000
	word and prefix consist only of lowercase English letters.
	At most 3 * 104 calls in total will be made to insert, search, and startsWith.

 
```

##Code
 ```
  

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
```