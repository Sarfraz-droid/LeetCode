class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a1;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '#'){
                if(a1.size() > 0)
                    a1.pop_back();
            }else{
                a1.push_back(s[i]);
            }
        }
        
        string a2;
        for(int i = 0;i<t.size();i++){
            if(t[i] == '#'){
                if(a2.size() > 0) 
                    a2.pop_back();
            }else{
                a2.push_back(t[i]);
            }
        }
        
        return a1 == a2;
    }
};