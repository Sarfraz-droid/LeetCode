class Solution {
public:
    
    vector<int> convertString(string str){
        vector<int> v;
        stringstream s(str);
        string word;
        
        while(s >> word){
            v.push_back(stoi(word));
        }
        
        return v;
    }
    
    int compareVersion(string version1, string version2) {
        replace(version1.begin(),version1.end(),'.',' ');
        replace(version2.begin(),version2.end(),'.',' ');
        
        vector<int> v1 = convertString(version1);
        vector<int> v2 = convertString(version2);

        int i = 0,j= 0;
        int n = v1.size(), m = v2.size();
        
        while(i<n and j<m){
            
            if(v1[i] < v2[j]){
                return -1;
            }else if(v1[i] == v2[j]){
                i++;
                j++;
            }else{
                return  1;
            }
        }
        
        while(i<n){
            if(v1[i] > 0)
                return 1;
            i++;
        }
        
        while(j<m){
            if(v2[j] > 0)
                return -1;
            j++;
        }
        
        return 0;
    }
    
    
    
};