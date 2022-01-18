class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0;i<flowerbed.size();i++){
            if(i>0 and flowerbed[i-1] == 1){
                continue;
            }else if(i<(flowerbed.size() -1) and flowerbed[i+1] == 1){
                continue;
            }else if(flowerbed[i] == 1){
                continue;
            }
            
            i++;
            n--;
        }
        
        return n <= 0;
    }
};