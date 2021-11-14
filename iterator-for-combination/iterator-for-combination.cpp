struct Node{
    string val;
    Node* next;
};


class CombinationIterator {
    string str;
    int length;
    int curr = -1;
    int comb_len;
    vector<string> combinations;
public:
    CombinationIterator(string characters, int combinationLength) {
        str  = characters;
        length = combinationLength;
        
        generateCombinations("",0);
        curr = -1;
        comb_len = combinations.size();
    }
    
    
    string next() {
        if(curr == comb_len - 1)
        {
            return "";
        }
        
        curr++;
        
        return combinations[curr];
    }
    
    bool hasNext() {
        return curr != comb_len -1;
    }
    
    void generateCombinations(string current,int pos){
        if(current.size() == length)
        {
            cout<<current<<"\n";
            combinations.push_back(current);
            return;
        }
        
        for(int i = pos;i<str.size();i++)
        {
            current.push_back(str[i]);
            generateCombinations(current,i+1);
            current.pop_back();
        }
        
    }
};



/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */