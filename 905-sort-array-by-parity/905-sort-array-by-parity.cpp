class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 0){
                swap(nums[pos],nums[i]);
                pos++;
            }
        }
        
        return nums;
    }
};