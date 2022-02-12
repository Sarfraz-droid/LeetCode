class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> mp;
        bool isPresent = false;
        
        for(auto word: wordList){
            if(word == endWord)
                isPresent = true;
            
            mp.insert(word);
        }
        
        if(!isPresent)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            depth+=1;
            int k =  q.size();
            
            while(k--){
                string curr = q.front();
                q.pop();
                
                for(int i = 0;i<curr.size();i++){
                    string temp = curr;
                    
                    for(char c = 'a'; c<='z';c++ ){
                        temp[i] = c;
                        
                        if(curr.compare(temp) == 0)
                            continue;
                        if(temp == endWord)
                            return depth+1;
                        else if(mp.find(temp) != mp.end()){
                            q.push(temp);
                            mp.erase(temp);
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        return 0;
        
    }
};