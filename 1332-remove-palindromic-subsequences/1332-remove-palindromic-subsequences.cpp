class Solution {
public:
    int removePalindromeSub(string s) {
         string st=s;    
        reverse(st.begin(), st.end());
        
        if(st==s)
            return 1;

        return 2;
        
    }};