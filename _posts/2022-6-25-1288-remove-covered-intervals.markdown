---
layout: post
title: 1288-remove-covered-intervals
date: 2022-06-25T14:28:04.957Z
---

```
1288. Remove Covered IntervalsMediumGiven an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c &lt;= a and b &lt;= d.

Return the number of remaining intervals.

&nbsp;
Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.


Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1


&nbsp;
Constraints:


	1 &lt;= intervals.length &lt;= 1000
	intervals[i].length == 2
	0 &lt;= li &lt;= ri &lt;= 105
	All the given intervals are unique.

 
```

##Code
 ```
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
            ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
        int n = intervals.size();
        int ans = n;
        sort(intervals.begin(),intervals.end(),customcomp);
        
        // output(intervals);
        
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
```
##NOTES.md
 ---
layout: post
title: 1288-remove-covered-intervals
date: 2022-06-25T14:28:04.956Z
---

```
​ 
```
