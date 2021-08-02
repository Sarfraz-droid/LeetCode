class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol(2);
        sol[0] = -1;
        sol[1] = -1;
        
        int f = 0;
        int l = nums.size() -1;
        while(f <= l)
        {
            int mid = (f+l)/2;
            
            if(nums[mid] < target)
            {
                f = mid+1;
            }else if(nums[mid] > target)
            {
                l = mid - 1;
            }else
            {
                sol[0] = mid;
                l = mid-1;
            }
        }
        
        f = 0;
        l = nums.size()-1;
        
        while(f <= l)
        {
            int mid = (f+l)/2;
            
            if(nums[mid] < target)
            {
                f = mid+1;
            }else if(nums[mid] > target)
            {
                l = mid - 1;
            }else
            {
                sol[1] = mid;
                f = mid + 1;
            }
        }
        return sol;
    }
};