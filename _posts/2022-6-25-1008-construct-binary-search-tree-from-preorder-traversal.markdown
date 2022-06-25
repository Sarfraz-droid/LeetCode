---
layout: post
title: 1008-construct-binary-search-tree-from-preorder-traversal
date: 2022-06-25T14:28:04.944Z
---

```
1008. Construct Binary Search Tree from Preorder TraversalMediumGiven an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

&nbsp;
Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]


Example 2:

Input: preorder = [1,3]
Output: [1,null,3]


&nbsp;
Constraints:


	1 &lt;= preorder.length &lt;= 100
	1 &lt;= preorder[i] &lt;= 1000
	All the values of preorder are unique.

 
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
    
    int pre = 0;
    int size = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {      
        size = preorder.size();
        pre = 0;
        
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        root->left = helper(preorder,INT_MIN,root->val);    
        root->right = helper(preorder,root->val,INT_MAX);

        return root;
    }
    
    TreeNode* helper(vector<int>& preorder,int mid,int last){
        if(pre == size or preorder[pre] > last or preorder[pre] < mid){
            return NULL;   
        }
        
        
        
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        
        root->left = helper(preorder,INT_MIN,root->val);
        root->right = helper(preorder,root->val,last);
        
        return root;        
    }
    
}; 
```
##NOTES.md
 ---
layout: post
title: 1008-construct-binary-search-tree-from-preorder-traversal
date: 2022-06-25T14:28:04.944Z
---

```
​ 
```
