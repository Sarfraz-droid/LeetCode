class Solution {
public:
    
    static bool customcomp(vector<int>& a,vector<int>& b){
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        pair<int,int> pr = {-1,-1};
        
        
        int n = intervals.size();
        int ans = n;
        sort(intervals.begin(),intervals.end(),customcomp);
        
        output(intervals);
        
        for(int i = 0;i<n;i++){
            pair<int,int> temp = {intervals[i][0],intervals[i][1]};
            if(temp.first >= pr.first and temp.second >= pr.first and pr.second >= temp.second){
                ans--;
                // cout<<temp.first<<" "<<temp.second<<endl;
            }
            
            if(pr.second < temp.second){
                pr = temp;
            }
        }
        
        return ans;
    }
    
    void output(vector<vector<int>> vec){
        for(int i = 0;i<vec.size();i++) cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
        
        cout<<endl;
    }
};