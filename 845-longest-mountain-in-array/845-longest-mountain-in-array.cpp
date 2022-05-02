class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = n-1;
        for(int i = 1;i<n;i++){
            if(arr[i-1] >= arr[i]){
                left[i] = i;
            }else{
                left[i] = left[i-1];
            }
            
            int j = n-1-i;
            
            if(arr[j+1] >= arr[j]){
                right[j] = j;
            }else{
                right[j] = right[j+1];
            }
        }

        
        int maxmount = INT_MIN;
        for(int i = 0;i<n;i++){
            if(left[i] == i or right[i] == i)
                maxmount = max(maxmount,0);
            else{
                int len = right[i] - left[i]+1;            
                maxmount = max(maxmount,len);
            }
        }
        
        return maxmount;
    }
};