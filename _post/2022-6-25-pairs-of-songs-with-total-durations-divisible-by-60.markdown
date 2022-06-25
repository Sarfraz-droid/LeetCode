---
layout: post
title: pairs-of-songs-with-total-durations-divisible-by-60
date: 2022-06-25T14:23:55.826Z
---

```
1010. Pairs of Songs With Total Durations Divisible by 60MediumYou are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i &lt; j with (time[i] + time[j]) % 60 == 0.

&nbsp;
Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60


Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.


&nbsp;
Constraints:


	1 &lt;= time.length &lt;= 6 * 104
	1 &lt;= time[i] &lt;= 500

 
```

##Code
 ```
  class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        
        for(int i = 0;i<time.size();i++)
        {
            cout<<time[i]%60<<" ";
            mp[time[i]%60]++;
        }
        
        cout<<endl;
        
        int counts = 0;
        
        for(auto x: mp)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        
        for(int i = 0;i<30;i++){
            if(i==0)
            {
                
                counts+=(mp[i]*(mp[i]-1))/2;
            }else{
                cout<<i<<" "<<mp[i]*mp[60-i]<<" \n";
                counts+=mp[i]*mp[60-i];
            }
                    
        }
        
        counts+= (mp[30]*(mp[30]-1))/2;
        
        return counts;
    }
}; 
```