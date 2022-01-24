class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        if(word[0] >= 'A' and word[0] <= 'Z'){
            if(word[1] >= 'A' and word[1] <= 'Z'){
                for(int i = 2;i<word.size();i++){
                    if(word[i] >='a' and word[i] <= 'z')
                        return false;
                }
                
                return true;
            }else{
                for(int i = 2;i<word.size();i++){
                    if(word[i] >= 'A' and word[i] <= 'Z')
                        return false;
                }
                
                return true;
            }
        }else{
            for(int i = 1;i<word.size();i++){
                if(word[i] >= 'A' and word[i]<= 'Z')
                    return false;
            }
            
            return true;
        }
    }
};