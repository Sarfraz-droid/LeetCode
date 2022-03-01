class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxprod = 0,lastprod = 0,n = nums.size();
        
        for(int i =0;i<n;i++){
            maxprod += i*nums[i];
        }
        
        lastprod = maxprod;
        
        for(int k = 1;k<n;k++){
            int change = sum - n*nums[n-k];
            int newprod = change + lastprod;
            lastprod = newprod;
            maxprod = max(newprod,maxprod);
        }
        
        return maxprod;
    }
    
};

// class Solution { // basically the change of product between rotations can be calculated by the observation that `change = sum-last_element*array.size` where the last_element is the last element of array before rotation.
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         int maxprod = 0, lastprod = 0, n = nums.size();
//         for(int i = 0; i < n; i++) // k = 0
//             maxprod += i*nums[i];
        
//         lastprod = maxprod;
        
//         for(int k = 1; k < n; k++) {
//             int change = sum-n*nums[n-k];
//             int newprod = change+lastprod;
//             lastprod = newprod;
//             maxprod = max(newprod,maxprod);
//         }
        
//         return maxprod;
//     }
// };