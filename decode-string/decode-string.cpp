class Solution {
public:
    
    string decode(string str,int& idx)
    {
        if(idx >= str.size())
            return "";
        string ans = "";
        int num = 0;
            
        while(idx<str.size() and isalpha(str[idx])) 
            ans.push_back(str[idx++]);
        
        while(isdigit(str[idx]))
        {
            num = num*10 + (str[idx] - '0');
            idx++;
        }
    
        if(str[idx] == ']')
            return ans;
        idx+= 1;

        string temp = decode(str,idx);        
        string res = "";
                
        for(int i = 0;i < num;i++)res += temp;
        idx += 1;
        return ans + res + decode(str, idx);

        
    }
    
    string decodeString(string s) {
        int idx = 0;
        
       return decode(s, idx);
    }
};