---
layout: post
title: flatten-binary-tree-to-linked-list
date: 2022-06-25T14:23:55.818Z
---

```
[Discussion Post (created on 15/10/2021 at 3:24)](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/1578516/Simple-C%2B%2B-Solution-or-Explanation)  
114. Flatten Binary Tree to Linked ListMediumGiven the root of a binary tree, flatten the tree into a "linked list":


	The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
	The "linked list" should be in the same order as a pre-order traversal of the binary tree.


&nbsp;
Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]


Example 2:

Input: root = []
Output: []


Example 3:

Input: root = [0]
Output: [0]


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 2000].
	-100 &lt;= Node.val &lt;= 100


&nbsp;
Follow up: Can you flatten the tree in-place (with O(1) extra space)? 
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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        TreeNode* ans = new TreeNode(root->val);
        TreeNode* temp = ans;
        FlattenTree(root->left,temp);
        FlattenTree(root->right,temp);
        
        root->left = NULL;
        root->right = ans->right;
    }
    
    void ChangeTree(TreeNode* root,TreeNode* ans)
    {

        
    }
    
    void inorder(TreeNode* ans)
    {
        if(ans == NULL)
            return;
        
        inorder(ans->left);
        cout<<ans->val<<" ";
        inorder(ans->right);
    }
    
    
    void FlattenTree(TreeNode* root,TreeNode* &ans)
    {
        if(root == NULL)
            return;
        
        
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        FlattenTree(root->left,ans);       
        
        FlattenTree(root->right,ans);
        
    }
}; 
```