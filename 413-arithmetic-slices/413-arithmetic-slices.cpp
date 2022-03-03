class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        vector<int> sum(n-1);
        
        for(int  i =1;i<n;i++){
            sum[i-1] = nums[i]-nums[i-1];
        }
        
        vector<int> count(n-1);
        
        for(int i = 1;i<sum.size();i++){
            if(sum[i-1] == sum[i])
                count[i] = count[i-1]+1;
        }
        
        return accumulate(count.begin(),count.end(),0);
        
    }
};