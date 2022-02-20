class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int ans = findDist(word1,word2,0,0);
        return ans;
    }
    
    int findDist(string word1,string word2,int i,int j){
        
        
        
        if(i == word1.size())
        {
            return word2.size()-j;
        }
        
        if(j == word2.size()){
            return word1.size() -i;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = 1e3+7;
        if(word1[i]==word2[j])
        {
            ans = findDist(word1,word2,i+1,j+1);
        }
        else
        {
            int opt1 = 1+findDist(word1,word2,i,j+1); //Insert
            int opt2 = 1+findDist(word1,word2,i+1,j); //Delete
            int opt3 = 1+findDist(word1,word2,i+1,j+1); //Replace
            ans = min({opt1, opt2, opt3});
        }
        return dp[i][j] = ans;
    }
};