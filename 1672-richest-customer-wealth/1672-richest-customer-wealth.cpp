class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for(int i = 0;i<accounts.size();i++){
            int sum = accumulate(accounts[i].begin(),accounts[i].end(),0);
            maxWealth = max(maxWealth,sum);
        }
        
        return maxWealth;
    }
};