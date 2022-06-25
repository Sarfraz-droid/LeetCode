---
layout: post
title: 211-design-add-and-search-words-data-structure
date: 2022-06-25T14:20:30.325Z
---

```
211. Design Add and Search Words Data StructureMediumDesign a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:


	WordDictionary()&nbsp;Initializes the object.
	void addWord(word) Adds word to the data structure, it can be matched later.
	bool search(word)&nbsp;Returns true if there is any string in the data structure that matches word&nbsp;or false otherwise. word may contain dots '.' where dots can be matched with any letter.


&nbsp;
Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


&nbsp;
Constraints:


	1 &lt;= word.length &lt;= 500
	word in addWord consists lower-case English letters.
	word in search consist of&nbsp; '.' or lower-case English letters.
	At most 50000&nbsp;calls will be made to addWord&nbsp;and search.

 
```

##Code
 ```
  struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL ? true : false;
    }

    Node* getKey(char ch){
        return links[ch-'a'];
    }    
    
    void addKey(char ch,Node* node){
        links[ch-'a'] = node;
    }
    
    bool search(string word,int i){
        
        if(word.size() == i){
            return flag==true;
        }
        
        // cout<<word<<" "<<i<<" ";
        
        if(word[i] == '.'){
            for(int j = 0;j<26;j++){
                if(links[j]!=NULL and links[j]->search(word,i+1)){
                    return true;
                }
            }
        }else{
            if(containsKey(word[i])){
                return links[word[i]-'a']->search(word,i+1);
            }else{
                return false;
            }
        }
        
        return false;
        
    }
    
    void setFlag(){
        flag = true;
    }
    
    void getFlag(){
        flag = false;
    }
};


class WordDictionary {
    Node* trie;
public:
    WordDictionary() {
        trie = new Node(); 
    }
    
    void addWord(string word) {
        Node* temp = trie;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            if(!temp->containsKey(ch)){
                temp->addKey(ch,new Node());   
            }
            
            temp = temp->getKey(ch);
        }
        
        temp->setFlag();
    }
    
    bool search(string word) {
        Node* temp = trie;
        
        bool ans = temp->search(word,0);
        // cout<<endl;
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */ 
```
##NOTES.md
 ---
layout: post
title: 211-design-add-and-search-words-data-structure
date: 2022-06-25T14:20:30.325Z
---

```
​ 
```
