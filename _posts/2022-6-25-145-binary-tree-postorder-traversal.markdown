---
layout: post
title: 145-binary-tree-postorder-traversal
date: 2022-06-25T14:28:04.962Z
---

```
145. Binary Tree Postorder TraversalEasyGiven the root of a&nbsp;binary tree, return the postorder traversal of its nodes' values.

&nbsp;
Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]


Example 2:

Input: root = []
Output: []


Example 3:

Input: root = [1]
Output: [1]


&nbsp;
Constraints:


	The number of the nodes in the tree is in the range [0, 100].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
    
    void postorder(TreeNode* root,vector<int>& ans){
        if(root == NULL)
            return;
        
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 145-binary-tree-postorder-traversal
date: 2022-06-25T14:28:04.961Z
---

```
​ 
```
