---
layout: post
title: 94-binary-tree-inorder-traversal
date: 2022-06-25T14:23:55.786Z
---

```
94. Binary Tree Inorder TraversalEasyGiven the root of a binary tree, return the inorder traversal of its nodes' values.

&nbsp;
Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]


Example 2:

Input: root = []
Output: []


Example 3:

Input: root = [1]
Output: [1]


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 100].
	-100 &lt;= Node.val &lt;= 100


&nbsp;
Follow up: Recursive solution is trivial, could you do it iteratively? 
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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        
        return ans;
        
    }
    
    void inorder(TreeNode* root,vector<int>& ans){
        if(root == NULL)
            return;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 94-binary-tree-inorder-traversal
date: 2022-06-25T14:23:55.786Z
---

```
​ 
```
