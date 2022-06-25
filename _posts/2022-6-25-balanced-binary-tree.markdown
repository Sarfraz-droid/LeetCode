---
layout: post
title: balanced-binary-tree
date: 2022-06-25T14:28:05.069Z
---

```
110. Balanced Binary TreeEasyGiven a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:


a binary tree in which the left and right subtrees of every node differ in height by no more than 1.


&nbsp;
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true


Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false


Example 3:

Input: root = []
Output: true


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 5000].
	-104 &lt;= Node.val &lt;= 104

 
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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root);
    }
    
    bool checkBalance(TreeNode* root){
        if(root == NULL)
            return true;
        
        int l = treeHeight(root->left);
        int r = treeHeight(root->right);
        
        bool rightCheck = checkBalance(root->right);
        bool leftCheck = checkBalance(root->left);
        
        
        return abs(l-r)<=1 and rightCheck and leftCheck;
    }
    
    int treeHeight(TreeNode* root)
    {
        
        if(root == NULL)
            return 0;
        return 1 + max(treeHeight(root->left),treeHeight(root->right));
    }
}; 
```