class Solution {
public:
    string removeDuplicates(string s) {
        string temp;
        string ans;
        for(int i =0;i<s.size();i++)
        {
            if(temp.back() == s[i])
            {
                temp.pop_back();
                
                continue;
            }
            
            temp.push_back(s[i]);
            
        }
        
        return temp;
    }
    
    
};