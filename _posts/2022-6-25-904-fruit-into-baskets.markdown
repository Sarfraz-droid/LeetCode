---
layout: post
title: 904-fruit-into-baskets
date: 2022-06-25T14:28:05.046Z
---

```
904. Fruit Into BasketsMediumYou are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:


	You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
	Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
	Once you reach a tree with fruit that cannot fit in your baskets, you must stop.


Given the integer array fruits, return the maximum number of fruits you can pick.

&nbsp;
Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.


Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].


Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


&nbsp;
Constraints:


	1 &lt;= fruits.length &lt;= 105
	0 &lt;= fruits[i] &lt; fruits.length

 
```

##Code
 ```
  class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int d=0;
        int maxLength = 0;
        int i = 0;
        
        for (int j = 0; j < fruits.size(); j++){
          if(map[fruits[j]]==0){d++;}    
          map[fruits[j]]++;

          if(d<=2){maxLength = max(maxLength, j - i + 1);}

          while(d > 2) {
            map[fruits[i]]--;  
            if(map[fruits[i]]==0){d--;}
            i++;                       
          }
        }
        return maxLength;    
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 904-fruit-into-baskets
date: 2022-06-25T14:28:05.046Z
---

```
​ 
```
