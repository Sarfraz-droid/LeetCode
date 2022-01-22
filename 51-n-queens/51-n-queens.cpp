class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queen(n);
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++)
                queen[i]+=".";
        }
        vector<vector<string>> ans;
        handleQueens(ans,queen,0,n);
        
        
        return ans;
    }
    
    void handleQueens(vector<vector<string>>& ans,vector<string>& queen,int r,int n){
        
        if(r >= n)
        {
            ans.push_back(queen);   
            return;
        }
        
        for(int i = 0;i<n;i++){
            if(canPlaceQueen(queen,r,i)){
                queen[r][i] = 'Q';
                handleQueens(ans,queen,r+1,n);
                queen[r][i] = '.';
            }
        }
    }
    bool canPlaceQueen(vector<string>& queen,int r,int c){
        int duprow = r;
        int dupcol = c;
        
        while(r >= 0 and c >= 0){
            if(queen[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        
        r = duprow;
        c = dupcol;
        
        while(r>=0 and c < queen.size()){
            if(queen[r][c] == 'Q')
                return false;
            c++;
            r--;
        }
        
        r = duprow;
        c = dupcol;
        
        while(r>=0){
            if(queen[r][c] == 'Q')
                return false;
            r--;
        }
        
        return true;
    }
};