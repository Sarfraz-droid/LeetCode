---
layout: post
title: largest-rectangle-in-histogram
date: 2022-06-25T14:52:08.138Z
---

```
84. Largest Rectangle in HistogramHardGiven an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

&nbsp;
Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.


Example 2:

Input: heights = [2,4]
Output: 4


&nbsp;
Constraints:


	1 &lt;= heights.length &lt;= 105
	0 &lt;= heights[i] &lt;= 104

 
```

##Code
 ```
  class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> stack {-1};
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            while(stack.size() > 1 && heights[i] < heights[stack.back()])
            {
                int h = heights[stack.back()];
                stack.pop_back();
                res = max(res, (i - stack.back() - 1) * h);
            }
            stack.push_back(i);
        }
        return res;
    }
}; 
```