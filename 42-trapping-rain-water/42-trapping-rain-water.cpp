class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = height[0];
        for(int i = 0,j=n-1;i<n;i++,j--){
            if(i == 0)
                left[i] = height[i];
            else
                left[i] = max(height[i],left[i-1]);
            
            if(j == n-1)
                right[j] = height[j];
            else
                right[j] = max(height[j],right[j+1]);   
        }
        
        for(int i = 0;i<n;i++){
            int w = min(right[i],left[i]) - height[i];
            // cout<<h<<" "<<w<<endl;
            sum+= w;
        }
        
        return sum;
    }
};