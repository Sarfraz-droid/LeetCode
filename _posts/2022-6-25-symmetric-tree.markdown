---
layout: post
title: symmetric-tree
date: 2022-06-25T14:28:05.124Z
---

```
101. Symmetric TreeEasyGiven the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

&nbsp;
Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true


Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 1000].
	-100 &lt;= Node.val &lt;= 100


&nbsp;
Follow up: Could you solve it both recursively and iteratively? 
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
    bool isSymmetric(TreeNode* root) {
        return findSymmetry(root->left,root->right);
    }
    
    bool findSymmetry(TreeNode* left,TreeNode* right)
    {
        if(left == NULL and right == NULL)
            return true;
        else if(left == NULL or right == NULL)
            return false;
        
        
        return findSymmetry(left->left,right->right) and left->val == right->val and findSymmetry(left->right,right->left);
    }
}; 
```