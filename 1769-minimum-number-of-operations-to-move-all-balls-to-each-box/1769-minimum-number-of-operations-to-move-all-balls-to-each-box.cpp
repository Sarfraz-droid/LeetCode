class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> result(n);
        
        int balls = boxes[0] == '1' ? 1 : 0;
        
        for(int i = 1;i<n;i++)
        {
            left[i] = left[i-1] + balls; 
            balls = boxes[i] =='1'? balls+1: balls;
        }
        
        balls = boxes[n-1] == '1' ? 1: 0;
        
        for(int i = n-2;i>=0;i--)
        {
            right[i] = right[i+1] + balls;
            balls = boxes[i] =='1'? balls+1: balls;
        }
        
        for(int i = 0;i<n;i++)
        {
            result[i] = left[i]+right[i];
        }
        
        return result;
    }
};