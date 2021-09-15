class Solution {
private:
    int low;
    int MaxLen;
public:
    
    void search(string s,int j,int k)
    {
        while(j>=0 && k<s.size() && s[j] == s[k])
        {
            j--;
            k++;
        }
        
        if(MaxLen < (k-j-1))
        {
            MaxLen = k-j-1;
            low = j + 1;
        }
    }
    
    string longestPalindrome(string s) {
        string ans;
        low = 0;
        MaxLen = 0;
        
        if(s.size() < 2)
            return s;
        
        for(int i = 0;i<s.size()-1;i++)
        {
            search(s,i,i);
            search(s,i,i+1);
        }
        
        return s.substr(low,MaxLen);
    }
};