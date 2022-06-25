---
layout: post
title: N meetings in one room - GFG
date: 2022-06-25T14:28:05.054Z
---

```
# N meetings in one room
## Easy 

                There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i]&nbsp;is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? 

Note:&nbsp;Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] =  { 1,3,0,5,8,5 } 
end[] =   { 2,4,6,7,9,9 } 
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)


Example 2:

Input:
N = 3
start[] =  { 10, 12, 20 } 
end[] =  { 20, 25, 30 } 
Output: 
1
Explanation:
Only one&nbsp;meetings can be held
with given start and end timings.


Your Task&nbsp;:
You don't need to read inputs or print anything. Complete the function maxMeetings()&nbsp;that takes two&nbsp;arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N&nbsp;≤ 105
0 ≤ start[i] &lt; end[i]&nbsp;≤ 105
 
             
```

##Code
 ```
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
```