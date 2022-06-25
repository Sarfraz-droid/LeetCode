---
layout: post
title: 42-trapping-rain-water
date: 2022-06-25T14:28:05.023Z
---

```
42. Trapping Rain WaterHardGiven n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

&nbsp;
Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


&nbsp;
Constraints:


	n == height.length
	1 &lt;= n &lt;= 2 * 104
	0 &lt;= height[i] &lt;= 105

 
```

##Code
 ```
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
```
##NOTES.md
 ---
layout: post
title: 42-trapping-rain-water
date: 2022-06-25T14:28:05.023Z
---

```
​ 
```
