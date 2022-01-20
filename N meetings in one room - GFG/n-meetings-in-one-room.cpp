// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {    
        vector<pair<int,int>> vec(n);
        
        for(int i = 0;i<n;i++){
            vec[i] = make_pair(end[i],start[i]);
        }
        
        sort(vec.begin(),vec.end());
        
        int prev = 0;
        int res = 1;
        
        for(int j = 1;j<n;j++){
            if(vec[prev].first < vec[j].second){
                res++;
                prev = j;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends