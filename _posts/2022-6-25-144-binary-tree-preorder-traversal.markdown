---
layout: post
title: 144-binary-tree-preorder-traversal
date: 2022-06-25T14:52:08.033Z
---

```
144. Binary Tree Preorder TraversalEasyGiven the root of a binary tree, return the preorder traversal of its nodes' values.

&nbsp;
Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        
        return ans;
    }
    
    void preorder(TreeNode* root,vector<int>& ans){
        if(root == NULL)
            return;
        
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 144-binary-tree-preorder-traversal
date: 2022-06-25T14:52:08.032Z
---

```
​ 
```
