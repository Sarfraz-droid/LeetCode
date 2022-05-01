class Solution {
public:
    string removeDigit(string number, char digit) {
        int index_to_del = -1;
        string before = "";
        int n = number.size();
        for(int i = 0;i<n;i++){
            if(number[i] == digit){
                if(before == ""){
                    before = number;
                    before.erase(i,1);
                }else{
                    string str = number;
                    str.erase(i,1);
                    
                    if(str > before){
                        before = str;
                    }
                }
            }
        }
        
        return before;
    }
};