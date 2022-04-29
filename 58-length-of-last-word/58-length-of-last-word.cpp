class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        // int s_n = s.size();
        while(n >= 0 and s[n] == ' '){
            n--;
        }
        int len = 0;
        while(n >=0 and s[n] != ' '){
            len++;
            n--;
        }
        
        return len;
    }
};