class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1,end = -1,maxVal = INT_MIN;
        
        for(int i = 0;i<nums.size();i++){
            if(maxVal > nums[i]){
                if(start == -1) start = i-1;
                while(start >= 1 and nums[start-1] > nums[i]) start--;
                end = i+1;
            }else
                maxVal = nums[i];
        }
        
        return end - start;
    }
};