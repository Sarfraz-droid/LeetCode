class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int n = seats.size();
        
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        int tmp = -1;
        for(int i = 0;i<n;i++){
            if(seats[i] == 1){
                tmp = i;
            }
            
            left[i] = tmp;
        }
        
        tmp = -1;
        for(int i = n-1;i>=0;i--){
            if(seats[i] == 1){
                tmp = i;
            }
            
            right[i] = tmp;
        }
        
        for(int i = 0;i<n;i++){
            if(seats[i] == 1) continue;

            int dist = INT_MAX;
            if(right[i] != -1){
                dist = right[i] - i;
            }
            
            if(left[i] != -1){
                dist = min(dist,(i - left[i]));
            }
            // cout<<i<<" "<<left[i]<<" "<<right[i]<<" "<<dist<<endl;
            ans  = max(ans,dist);
        }
        
        return ans;
    }
};