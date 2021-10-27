class Solution {
public:
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n,-1);
        return !(n%2);
    }
    
//     bool findStones(vector<int> &piles,int i,vector<int> &dp)
//     {
//         if(i == piles.size())
//             return false;
        
//         if(dp[i] != -1)
//             return dp[i];
        
        
//     }
    
};