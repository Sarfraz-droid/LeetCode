---
layout: post
title: 605-can-place-flowers
date: 2022-06-25T14:23:55.775Z
---

```
605. Can Place FlowersEasyYou have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

&nbsp;
Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

&nbsp;
Constraints:


	1 &lt;= flowerbed.length &lt;= 2 * 104
	flowerbed[i] is 0 or 1.
	There are no two adjacent flowers in flowerbed.
	0 &lt;= n &lt;= flowerbed.length

 
```

##Code
 ```
  class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0;i<flowerbed.size();i++){
            if(i>0 and flowerbed[i-1] == 1){
                continue;
            }else if(i<(flowerbed.size() -1) and flowerbed[i+1] == 1){
                continue;
            }else if(flowerbed[i] == 1){
                continue;
            }
            
            i++;
            n--;
        }
        
        return n <= 0;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 605-can-place-flowers
date: 2022-06-25T14:23:55.775Z
---

```
​ 
```
