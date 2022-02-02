class Solution {
public:
    int maxlen;
    int low;
    string longestPalindrome(string s) {
        
        string ans;
        maxlen = 0;
        low = 0;
        for(int i =0;i<s.size();i++){
            lString(i-1,i,s);
            lString(i,i,s);
        }
        
        return s.substr(low,maxlen);
    }
    
    void lString(int a,int b,string s){
        while(a>=0 and b<s.size() and s[a] == s[b])
        {
            a--;
            b++;
        }
        
        
        if(maxlen < (b-a-1)){
            maxlen = b-a-1;
            low = a+1;
        }
    } 
};