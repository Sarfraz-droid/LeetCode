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