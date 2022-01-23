class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_n = to_string(low).size();
        int high_n = to_string(high).size();
        string str = "123456789";
        vector<int> ans;
        for(int i = low_n;i<= high_n;i++){
            cout<<i<<" ";
             for(int j = 0;j<(str.size() - i+1);j++){
                 string s = str.substr(j,i);
                 int num = stoi(s);
                 cout<<num<<" ";
                 
                 if(num >= low and num <= high){
                     ans.push_back(num);
                 }
             }
            cout<<endl;
        }
        
        return ans;
    }
};