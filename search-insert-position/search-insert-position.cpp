class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int f = 0;
        int l = nums.size() - 1;
        
        int index = nums.size();
        while(f<=l)
        {
            int mid = (f+l)/2;
            
            if(nums[mid] < target)
            {
                f = mid+1;
            }else if(nums[mid] > target)
            {
                index = mid;
                l = mid-1;
            }else
            {
                index = mid;
                break;
            }
        }
        return index;
    }
};