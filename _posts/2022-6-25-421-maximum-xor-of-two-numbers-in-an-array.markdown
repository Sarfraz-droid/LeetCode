---
layout: post
title: 421-maximum-xor-of-two-numbers-in-an-array
date: 2022-06-25T14:28:05.024Z
---

```
421. Maximum XOR of Two Numbers in an ArrayMediumGiven an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 &lt;= i &lt;= j &lt; n.

&nbsp;
Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.


Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 2 * 105
	0 &lt;= nums[i] &lt;= 231 - 1

 
```

##Code
 ```
  struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie{
  private: Node *root;
  public:
    Trie() {
      root = new Node();
    }

    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }

    
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};

class Solution {
public:
    
    int findMaximumXOR(vector<int>& nums) {
        
        Trie t;
        
        for(int i = 0;i<nums.size();i++){
            t.insert(nums[i]);
        }        
            
        int maxi = 0;
        
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi, t.findMax(nums[i]));
        }
        
        return maxi;
        
    }
}; 
```