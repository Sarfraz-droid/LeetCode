---
layout: post
title: 653-two-sum-iv-input-is-a-bst
date: 2022-06-25T14:52:08.092Z
---

```
653. Two Sum IV - Input is a BSTEasyGiven the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

&nbsp;
Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true


Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 104].
	-104&nbsp;&lt;= Node.val &lt;= 104
	root is guaranteed to be a valid binary search tree.
	-105&nbsp;&lt;= k &lt;= 105

 
```

##Code
 ```
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        inorder(root,mp);
        
        for(auto x : mp){
            if((k-x.first) == x.first){
                if(x.second > 1)
                    return true;
            }else{
                if(mp.find(k-x.first) != mp.end()){
                    return true;
                }
            }
        }
        
        
        return false;
    }
    
    void inorder(TreeNode* root,unordered_map<int,int>& mp){
        if(root == NULL)
            return;
        
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 653-two-sum-iv-input-is-a-bst
date: 2022-06-25T14:52:08.092Z
---

```
​ 
```
