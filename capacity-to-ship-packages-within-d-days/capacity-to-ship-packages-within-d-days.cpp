class Solution {
public:
    
    bool isAllowed(vector<int>& weights,int days,int wt)
    {
        int d = 1;
        int temp = 0;
        for(int i =0 ;i<weights.size();i++)
        {
            if(weights[i] > wt)
                return false;
            if(temp + weights[i] <= wt)
            {
                temp+= weights[i];
            }else
            {
                temp = weights[i];
                d++;
            }
        }
        
        cout<<"\nDays : "<<d;
        
        return d <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l =0;
        int r = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(isAllowed(weights,days,mid))
            {
                ans = mid;
                r = mid-1;
            }else
                l = mid+1;
        }
        
        return ans;
        
    }
};