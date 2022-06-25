---
layout: post
title: diameter-of-binary-tree
date: 2022-06-25T14:28:05.075Z
---

```
543. Diameter of Binary TreeEasyGiven the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

&nbsp;
Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].


Example 2:

Input: root = [1,2]
Output: 1


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 104].
	-100 &lt;= Node.val &lt;= 100

 
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
    int d;
    
    int maxdia(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = maxdia(root->left);
        int right = maxdia(root->right);
        
        d = max(d,left+right);
        
        return max(left,right) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        d = 0;
        
        maxdia(root);
        
        return d;
        
    }
}; 
```