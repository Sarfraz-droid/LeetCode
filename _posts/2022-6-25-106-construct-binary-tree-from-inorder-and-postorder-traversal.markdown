---
layout: post
title: 106-construct-binary-tree-from-inorder-and-postorder-traversal
date: 2022-06-25T14:20:30.289Z
---

```
106. Construct Binary Tree from Inorder and Postorder TraversalMediumGiven two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

&nbsp;
Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


&nbsp;
Constraints:


	1 &lt;= inorder.length &lt;= 3000
	postorder.length == inorder.length
	-3000 &lt;= inorder[i], postorder[i] &lt;= 3000
	inorder and postorder consist of unique values.
	Each value of postorder also appears in inorder.
	inorder is guaranteed to be the inorder traversal of the tree.
	postorder is guaranteed to be the postorder traversal of the tree.

 
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
    int postIndex = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size()-1;
        
        return makeTree(inorder,postorder,0,inorder.size()-1);
        
    }
    
    TreeNode* makeTree(vector<int>& inorder,vector<int>& postorder,int start,int end){
        if(start > end)
            return NULL;
        TreeNode* node = new TreeNode(postorder[postIndex]);
        postIndex--;        
        int mid = midIndex(inorder,start,end,node->val);        
        if(mid!=-1){
            node->right = makeTree(inorder,postorder,mid+1,end);
            node->left = makeTree(inorder,postorder,start,mid-1);
        }
        
        return node;
    }
    
    int midIndex(vector<int>& inorder,int start,int end,int val){
        for(int i = start;i<=end;i++){
            if(val == inorder[i])
                return i;
        }
        
        return -1;
    }
    
    
}; 
```
##NOTES.md
 ---
layout: post
title: 106-construct-binary-tree-from-inorder-and-postorder-traversal
date: 2022-06-25T14:20:30.289Z
---

```
​ 
```
