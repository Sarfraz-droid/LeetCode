---
layout: post
title: 98-validate-binary-search-tree
date: 2022-06-25T14:28:05.050Z
---

```
98. Validate Binary Search TreeMediumGiven the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:


	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.


&nbsp;
Example 1:

Input: root = [2,1,3]
Output: true


Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 104].
	-231 &lt;= Node.val &lt;= 231 - 1

 
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
        void inorder(TreeNode* root,vector<int> &vec)
    {
        if(root== NULL)
            return;
        
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        
        for(int i = 0;i<(vec.size()-1);i++)
        {
            if(vec[i] >= vec[i+1])
            {
                return false;
            }
        }
        
        return true;
        
    }


}; 
```
##NOTES.md
 ---
layout: post
title: 98-validate-binary-search-tree
date: 2022-06-25T14:28:05.050Z
---

```
​ 
```
