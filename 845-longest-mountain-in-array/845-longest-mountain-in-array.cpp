class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        for(int i = 1;i<n;i++){
            if(arr[i-1] >= arr[i]){
                left[i] = i;
            }else{
                left[i] = left[i-1];
            }
        }
        right[n-1] = n-1;
        for(int i = n-2;i>=0;i--){
            if(arr[i+1] >= arr[i]){
                right[i] = i;
            }else{
                right[i] = right[i+1];
            }
        }
        
        int maxmount = INT_MIN;
        for(int i = 0;i<n;i++){
            if(left[i] == i or right[i] == i)
                maxmount = max(maxmount,0);
            else{
                
                int len = right[i] - left[i]+1;            
                
                cout<<"\n"<<arr[i]<<" = "<<len<<" from "<<left[i]<<" to "<<right[i];
                maxmount = max(maxmount,len);
            }
        }
        
        return maxmount;
    }
};