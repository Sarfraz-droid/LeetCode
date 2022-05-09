class Solution {
public:
    int minPartitions(string n) {
        int len = n.size();
        int ans = 0;
        for(int i = 0;i<len;i++){
            int k = n[i] - '0';
            ans = max(ans,k);
        }
        
        return ans;
    }
};