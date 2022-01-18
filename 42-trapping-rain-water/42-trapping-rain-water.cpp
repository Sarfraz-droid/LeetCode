class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        
        for(int i = 1;i<n;i++){
            left[i] = max(height[i],left[i-1]);
            // cout<<left[i]<<" ";
        }
        // cout<<endl;
        
        right[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            
            
            right[i] = max(height[i],right[i+1]);
            // cout<<right[i]<<" ";
        }
        // cout<<endl;
        
        for(int i = 0;i<n;i++){
            int h = min(right[i],left[i]);
            int w = h - height[i];
            // cout<<h<<" "<<w<<endl;
            sum+= w;
        }
        
        return sum;
    }
};