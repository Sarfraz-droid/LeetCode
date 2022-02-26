class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int d=0;
        int maxLength = 0;
        int i = 0;
        
        for (int j = 0; j < fruits.size(); j++){
          if(map[fruits[j]]==0){d++;}    
          map[fruits[j]]++;

          if(d<=2){maxLength = max(maxLength, j - i + 1);}

          while(d > 2) {
            map[fruits[i]]--;  
            if(map[fruits[i]]==0){d--;}
            i++;                       
          }
        }
        return maxLength;    
    }
};