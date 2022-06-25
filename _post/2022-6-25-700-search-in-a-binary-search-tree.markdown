---
layout: post
title: 700-search-in-a-binary-search-tree
date: 2022-06-25T14:23:55.778Z
---

```
700. Search in a Binary Search TreeEasyYou are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

&nbsp;
Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]


Example 2:

Input: root = [4,2,7,1,3], val = 5
Output: []


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 5000].
	1 &lt;= Node.val &lt;= 107
	root is a binary search tree.
	1 &lt;= val &lt;= 107

 
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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val == val) 
            return root;
        
        TreeNode* left = searchBST(root->left,val);
        TreeNode* right = searchBST(root->right,val);
        
        return left != NULL ? left : right;
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 700-search-in-a-binary-search-tree
date: 2022-06-25T14:23:55.778Z
---

```
​ 
```
